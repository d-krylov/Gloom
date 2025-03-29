#include "gloom/mathematics/shapes.h"

namespace Gloom {

std::vector<Vector3f> GetHexahedronVertices() {
  return std::vector<Vector3f>{
#define HEXAHEDRON_VERTICES
#include "assets/shapes/hexahedron.def"
  };
}

std::vector<uint32_t> GetHexahedronIndices() {
  return std::vector<uint32_t>{
#define HEXAHEDRON_INDICES
#include "assets/shapes/hexahedron.def"
  };
}

std::vector<Vector3f> GetHexahedronNormals() {
  return std::vector<Vector3f>{
#define HEXAHEDRON_NORMALS
#include "assets/shapes/hexahedron.def"
  };
}

std::vector<Vector2f> GetHexahedronUV() {
  return std::vector<Vector2f>{
#define HEXAHEDRON_UV
#include "assets/shapes/hexahedron.def"
  };
}

std::array<Vertex, 36> MakeHexahedron() {
  auto result = std::array<Vertex, 36>();
  auto vertices = GetHexahedronVertices();
  auto normals = GetHexahedronNormals();
  auto indices = GetHexahedronIndices();
  for (auto i = 0; i < result.size(); i++) {
    result[i].position = vertices[indices[i]];
    result[i].normal = normals[i / 6];
  }
  return result;
}

std::array<TexturedVertex, 36> MakeTexturedHexahedron() {
  auto result = std::array<TexturedVertex, 36>();
  auto vertices = GetHexahedronVertices();
  auto normals = GetHexahedronNormals();
  auto indices = GetHexahedronIndices();
  auto uv = GetHexahedronUV();
  for (auto i = 0; i < result.size(); i++) {
    result[i].position = vertices[indices[i]];
    result[i].normal = normals[i / 6];
    result[i].uv = uv[i % 6];
  }
  return result;
}

} // namespace Gloom
