#include "image.h"

namespace Gloom {

std::vector<uint32_t> MakeChessTexture(uint32_t width, uint32_t height, uint32_t x_count, uint32_t y_count) {
  std::vector<uint32_t> result(width * height);
  auto x_size = width / x_count;
  auto y_size = height / y_count;
  for (auto x = 0; x < width; x++) {
    for (auto y = 0; y < height; y++) {
      auto is_black = (x / x_size + y / y_size) % 2;
      result[y * width + x] = is_black ? GetRGBA(255, 255, 255, 255) : GetRGBA(0, 0, 0, 255);
    }
  }
  return result;
}

} // namespace Gloom