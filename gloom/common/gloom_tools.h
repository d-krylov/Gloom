#ifndef GLOOM_TOOLS_H
#define GLOOM_TOOLS_H

#include <filesystem>

namespace Gloom {

std::string LoadFile(const std::filesystem::path &path);
std::filesystem::path GetRootPath();
std::filesystem::path GetShadersPath();

} // namespace Gloom

#endif // GLOOM_TOOLS_H