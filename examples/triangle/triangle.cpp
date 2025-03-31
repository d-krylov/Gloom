#include "gloom/common/gloom.h"
#include <iostream>
#include <array>

namespace GL = Gloom;

int main() {

  GL::GLFWWindow window("Triangle", 800, 600);

  GL::Descriptor vertex_array;
  GL::Descriptor vertex_buffer;

  GL::CreateVertexArray(vertex_array);
  GL::CreateBuffer(vertex_buffer);
  GL::SetVertexArrayVertexBuffer(vertex_array, vertex_buffer, 0, 20, 0);

  GL::SetAttributeFormat(vertex_array, 0, 2, GL::VertexAttributeType::FLOAT, 0, false);
  GL::SetAttributeFormat(vertex_array, 1, 3, GL::VertexAttributeType::FLOAT, 8, false);

  GL::SetAttributeBinding(vertex_array, 0, 0);
  GL::SetAttributeBinding(vertex_array, 1, 0);

  GL::EnableVertexArrayAttribute(vertex_array, 0);
  GL::EnableVertexArrayAttribute(vertex_array, 1);

  auto program = GL::CreateProgram();
  auto vertex_shader = GL::CreateShader(GL::ShaderType::VERTEX);
  auto fragment_shader = GL::CreateShader(GL::ShaderType::FRAGMENT);

  // clang-format off
  std::array data{
    -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 
    +0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
    +0.0f, +0.5f, 0.0f, 0.0f, 1.0f,
  };
  // clang-format on

  GL::CreateBufferStorage<float>(vertex_buffer, GL::BufferStorageMask::DYNAMIC_STORAGE_BIT, data);
  GL::ShaderSource(vertex_shader, GL::LoadFile(GL::GetShadersPath() / "common" / "position_color_2d.vert"));
  GL::ShaderSource(fragment_shader, GL::LoadFile(GL::GetShadersPath() / "common" / "position_color_2d.frag"));
  GL::CompileShaders(vertex_shader, fragment_shader);
  GL::AttachShaders(program, vertex_shader, fragment_shader);
  GL::LinkProgram(program);

  while (window.ShouldClose() == false) {
    window.PollEvents();

    auto size = window.GetSize();

    GL::SetViewport(0, 0, size.width_, size.height_);

    GL::SetClearColor(0.2f, 0.2f, 0.5f, 0.0f);
    GL::Clear(Gloom::ClearBufferMask::COLOR_BUFFER_BIT);

    GL::BindVertexArray(vertex_array);
    GL::UseProgram(program);
    GL::DrawArrays(0, 3, GL::PrimitiveType::TRIANGLES);

    window.Update();
  }

  return 0;
}