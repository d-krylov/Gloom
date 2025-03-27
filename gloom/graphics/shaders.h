#ifndef GLOOM_SHADERS_H
#define GLOOM_SHADERS_H

#include <string_view>

namespace Gloom {

std::string_view GetPlaneVertexShader();
std::string_view GetPlaneFragmentShader();
std::string_view GetPlaneTextureVertexShader();
std::string_view GetPlaneTextureFragmentShader();

} // namespace Gloom

#endif // GLOOM_SHADERS_H