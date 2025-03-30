#include "gloom/common/gloom.h"
#include <iostream>
#include <array>
#include <vector>

namespace GL = Gloom;

int main() {

  GL::GLFWWindow window("Texture", 800, 600);

  GL::Descriptor vertex_array;
  GL::Descriptor vertex_buffer, index_buffer;
  GL::Descriptor texture;

  auto texture_image = GL::MakeChessTexture(800, 600, 25, 25);

  GL::CreateTexture(texture, GL::TextureTarget::TEXTURE_2D);
  GL::CreateTextureStorage(texture, 1, 800, 600, GL::InternalFormat::RGBA8);
  GL::TextureSubImage<uint32_t>(texture, 800, 600, GL::PixelFormat::RGBA, GL::PixelType::UNSIGNED_BYTE, texture_image, 0, 0, 0);

  GL::CreateVertexArray(vertex_array);

  GL::CreateBuffers(vertex_buffer, index_buffer);
  GL::SetVertexArrayVertexBuffer(vertex_array, vertex_buffer, 0, 28, 0);
  GL::SetVertexArrayElementBuffer(vertex_array, index_buffer);

  GL::SetAttributeFormat(vertex_array, 0, 2, GL::VertexAttributeType::FLOAT, 0, false);
  GL::SetAttributeFormat(vertex_array, 1, 3, GL::VertexAttributeType::FLOAT, 8, false);
  GL::SetAttributeFormat(vertex_array, 2, 2, GL::VertexAttributeType::FLOAT, 20, false);

  GL::SetAttributeBinding(vertex_array, 0, 0);
  GL::SetAttributeBinding(vertex_array, 1, 0);
  GL::SetAttributeBinding(vertex_array, 2, 0);

  GL::EnableVertexArrayAttribute(vertex_array, 0);
  GL::EnableVertexArrayAttribute(vertex_array, 1);
  GL::EnableVertexArrayAttribute(vertex_array, 2);

  auto program = GL::CreateProgram();
  auto vertex_shader = GL::CreateShader(GL::ShaderType::VERTEX);
  auto fragment_shader = GL::CreateShader(GL::ShaderType::FRAGMENT);

  // clang-format off
  std::array data{
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    +0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
    +0.5f, +0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
    -0.5f, +0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f
  };
  // clang-format on

  std::array indices{0, 1, 2, 2, 3, 0, 0, 1, 2};

  GL::CreateBufferStorage<float>(vertex_buffer, GL::BufferStorageMask::DYNAMIC_STORAGE_BIT, data);
  GL::CreateBufferStorage<int32_t>(index_buffer, GL::BufferStorageMask::DYNAMIC_STORAGE_BIT, indices);
  GL::ShaderSource(vertex_shader, GL::LoadFile(GL::GetShadersPath() / "common" / "position_color_uv_2d.vert"));
  GL::ShaderSource(fragment_shader, GL::LoadFile(GL::GetShadersPath() / "common" / "position_color_uv_2d.frag"));
  GL::CompileShaders(vertex_shader, fragment_shader);
  GL::AttachShaders(program, vertex_shader, fragment_shader);
  GL::LinkProgram(program);

  int32_t active_resources{0};
  GL::GetProgramInterface(program, GL::ProgramInterface::PROGRAM_INPUT, GL::ProgramInterfaceParameterName::ACTIVE_RESOURCES,
                          active_resources);
  std::cout << active_resources << std::endl;

  for (auto i = 0; i < active_resources; i++) {

    std::array properties{GL::ProgramResourceProperty::NAME_LENGTH, GL::ProgramResourceProperty::TYPE,
                          GL::ProgramResourceProperty::LOCATION};

    auto ret = GL::GetProgramResource(program, GL::ProgramInterface::PROGRAM_INPUT, i, properties);

    auto name = GL::GetProgramResourceName(program, GL::ProgramInterface::PROGRAM_INPUT, i, ret[0]);

    std::cout << name << " " << GL::GetAttributeTypeName(GL::AttributeType(ret[1])) << std::endl;
  }

  auto texture_location = GL::GetUniformLocation(program, "u_texture");

  while (window.ShouldClose() == false) {
    window.PollEvents();

    auto size = window.GetSize();

    GL::SetViewport(0, 0, size.width_, size.height_);

    GL::SetClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    GL::Clear(Gloom::ClearBufferMask::COLOR_BUFFER_BIT);

    GL::BindVertexArray(vertex_array);
    GL::BindTextureUnit(texture, 0);
    GL::UseProgram(program);
    GL::SetUniform(texture_location, 0);
    GL::DrawElements(0, 6, 3, GL::DrawElementsType::UNSIGNED_INT, GL::PrimitiveType::TRIANGLES);

    window.Update();
  }

  return 0;
}