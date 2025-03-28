#include "gloom_tools.h"
#include <fstream>
// #define NDEBUG
#include <cassert>

namespace Gloom {

std::string LoadFile(const std::filesystem::path &path) {
  assert(std::filesystem::exists(path));
  std::ifstream file(path.c_str());
  std::string source{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
  return source;
}

} // namespace Gloom