#include "gloom_tools.h"
#include <fstream>
// #define NDEBUG
#include <cassert>

namespace Gloom {

std::filesystem::path GLOOM_ROOT = GLOOM_PROJECT_SOURCE_DIR;

std::string LoadFile(const std::filesystem::path &path) {
  assert(std::filesystem::exists(path));
  std::ifstream file(path.c_str());
  std::string source{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
  return source;
}

std::filesystem::path GetRootPath() {
  return GLOOM_ROOT;
}

std::filesystem::path GetShadersPath() {
  return GetRootPath() / "shaders";
}

} // namespace Gloom