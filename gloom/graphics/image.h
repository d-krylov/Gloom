#ifndef GLOOM_IMAGE_H
#define GLOOM_IMAGE_H

#include "gloom/graphics/graphics_types.h"
#include <vector>

namespace Gloom {

std::vector<uint32_t> MakeChessTexture(uint32_t width, uint32_t height, uint32_t x_count, uint32_t y_count);

} // namespace Gloom

#endif // GLOOM_IMAGE_H