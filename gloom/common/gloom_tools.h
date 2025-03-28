#ifndef GLOOM_TOOLS_H
#define GLOOM_TOOLS_H

#include <filesystem>

namespace Gloom {

std::string LoadFile(const std::filesystem::path &path);

inline const std::filesystem::path GLOOM_ROOT = GLOOM_PROJECT_SOURCE_DIR;
inline const std::filesystem::path GLOOM_SHADERS_DIR = GLOOM_ROOT / "shaders";

} // namespace Gloom

#endif // GLOOM_TOOLS_H