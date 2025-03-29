#include "gloom/common/gloom.h"
#include <iostream>
#include <array>
#include <vector>

namespace GL = Gloom;

int main() {

  GL::GLFWWindow window("Box", 800, 600);

  GL::Descriptor vertex_array;
  GL::Descriptor vertex_buffer, index_buffer;

  GL::CreateVertexArray(vertex_array);

  auto box_vertices = GL::MakeHexahedron();

  GL::CreateBuffer(vertex_buffer);
  GL::SetVertexArrayVertexBuffer(vertex_array, vertex_buffer, 0, sizeof(GL::Vertex), 0);

  GL::SetAttributeFormat(vertex_array, 0, 3, GL::VertexAttributeType::FLOAT, 0, false);
  GL::SetAttributeFormat(vertex_array, 1, 3, GL::VertexAttributeType::FLOAT, 12, false);

  GL::SetAttributeBinding(vertex_array, 0, 0);
  GL::SetAttributeBinding(vertex_array, 1, 0);

  GL::EnableVertexArrayAttribute(vertex_array, 0);
  GL::EnableVertexArrayAttribute(vertex_array, 1);

  auto program = GL::CreateProgram();
  auto vertex_shader = GL::CreateShader(GL::ShaderType::VERTEX);
  auto fragment_shader = GL::CreateShader(GL::ShaderType::FRAGMENT);

  GL::CreateBufferStorage<GL::Vertex>(vertex_buffer, GL::BufferStorageMask::DYNAMIC_STORAGE_BIT, box_vertices);

  GL::ShaderSource(vertex_shader, GL::LoadFile(GL::GetShadersPath() / "common" / "position_normal_3d.vert"));
  GL::ShaderSource(fragment_shader, GL::LoadFile(GL::GetShadersPath() / "common" / "position_normal_3d.frag"));
  GL::CompileShaders(vertex_shader, fragment_shader);
  GL::AttachShaders(program, vertex_shader, fragment_shader);
  GL::LinkProgram(program);

  auto projection_location = GL::GetUniformLocation(program, "u_projection_matrix");
  auto view_location = GL::GetUniformLocation(program, "u_view_matrix");
  auto model_location = GL::GetUniformLocation(program, "u_model_matrix");

  GL::Matrix4f projection_matrix = linalg::perspective_matrix(1.0f, 1.3f, 0.1f, 100.0f);
  GL::Matrix4f view_matrix =
    linalg::lookat_matrix(GL::Vector3f(0.0f, 0.0f, 4.0f), GL::Vector3f(0.0f, 0.0f, 3.0f), GL::Vector3f(0.0f, 1.0f, 0.0f));

  auto translate = linalg::translation_matrix(GL::Vector3f(0.0f, -2.0f, 0.0f));

  GL::Enable(GL::Capabilities::DEPTH_TEST);

  while (window.ShouldClose() == false) {
    window.PollEvents();

    auto size = window.GetSize();

    GL::SetViewport(0, 0, size.width_, size.height_);

    GL::SetClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    GL::Clear(Gloom::ClearBufferMask::COLOR_BUFFER_BIT | GL::ClearBufferMask::DEPTH_BUFFER_BIT);

    GL::BindVertexArray(vertex_array);
    GL::UseProgram(program);

    GL::SetUniform(projection_location, projection_matrix, false);
    GL::SetUniform(view_location, view_matrix, false);
    GL::SetUniform(model_location, translate, false);
    GL::DrawArrays(0, box_vertices.size(), GL::PrimitiveType::TRIANGLES);

    window.Update();
  }

  return 0;
}