#include "graphics_types.h"
#include <unordered_map>

namespace Gloom {

struct FormatInformation {
  PixelFormat pixel_format_;
};

std::unordered_map<InternalFormat, FormatInformation> format_information{
#define INTERNAL_FORMAT(X, Y, R, G, B, A) {InternalFormat::X, {PixelFormat::Y}},
#include "graphics_types.def"
};

uint32_t GetRGBA(uint32_t red, uint32_t green, uint32_t blue, uint32_t alpha) {
  return (alpha << 24) | (blue << 16) | (green << 8) | red;
}

uint32_t GetDrawElementsTypeSize(DrawElementsType type) {
  switch (type) {
  case DrawElementsType::UNSIGNED_BYTE:
    return 1;
  case DrawElementsType::UNSIGNED_SHORT:
    return 2;
  case DrawElementsType::UNSIGNED_INT:
    return 4;
  default:
    std::unreachable();
    break;
  }
}

} // namespace Gloom
