#include "shaders.h"

namespace Gloom {

std::string_view GetPlaneVertexShader() {
  std::string_view shader =
#include "shaders/common/plane.v.glsl"
    ;
  return shader;
}

std::string_view GetPlaneFragmentShader() {
  std::string_view shader =
#include "shaders/common/plane.f.glsl"
    ;
  return shader;
}

std::string_view GetPlaneTextureVertexShader() {
  std::string_view shader =
#include "shaders/common/plane_texture.v.glsl"
    ;
  return shader;
}

std::string_view GetPlaneTextureFragmentShader() {
  std::string_view shader =
#include "shaders/common/plane_texture.f.glsl"
    ;
  return shader;
}

} // namespace Gloom
