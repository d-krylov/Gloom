#ifndef GLOOM_SHAPES_H
#define GLOOM_SHAPES_H

#include "gloom/mathematics/mathematics_types.h"
#include <vector>

namespace Gloom {

struct Vertex {
  Vector3f position;
  Vector3f normal;
};

struct TexturedVertex {
  Vector3f position;
  Vector3f normal;
  Vector2f uv;
};

std::vector<Vector3f> GetHexahedronVertices();
std::vector<Vector3f> GetHexahedronNormals();
std::vector<uint32_t> GetHexahedronIndices();
std::vector<Vector2f> GetHexahedronUV();
std::array<Vertex, 36> MakeHexahedron();
std::array<TexturedVertex, 36> MakeTexturedHexahedron();

} // namespace Gloom

#endif // GLOOM_SHAPES_H