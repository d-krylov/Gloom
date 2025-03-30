#ifndef GLOOM_IMAGE_H
#define GLOOM_IMAGE_H

#include <cstdint>
#include <vector>

namespace Gloom {

uint32_t GetRGBA(uint32_t red, uint32_t green, uint32_t blue, uint32_t alpha);

std::vector<uint32_t> MakeChessTexture(uint32_t width, uint32_t height, uint32_t x_count, uint32_t y_count);

} // namespace Gloom

#endif // GLOOM_IMAGE_H