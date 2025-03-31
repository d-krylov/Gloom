#include "graphics_types.h"
#include <unordered_map>
#include <numeric>

namespace Gloom {

std::unordered_map<InternalFormat, FormatInformation> format_information{
#define INTERNAL_FORMAT(X, Y, R, G, B, A) {InternalFormat::X, {PixelFormat::Y}},
#include "graphics_types.def"
};

std::unordered_map<AttributeType, AttributeInformation> attribute_information{
#define ATTRIBUTE_TYPE(NAME, COMPONENTS, VERTEX) {AttributeType::NAME, {COMPONENTS, VertexAttributeType::VERTEX}},
#include "graphics_types.def"
};

AttributeInformation GetAttributeInformation(AttributeType type) {
  return attribute_information[type];
}

uint32_t GetAttributeSize(AttributeType type) {
  auto information = GetAttributeInformation(type);
  return information.components_ * GetVertexAttributeSize(information.vertex_attribute_type_);
}

uint32_t GetStride(std::span<const AttributeType> types) {
  return std::accumulate(types.begin(), types.end(), 0, [](auto total, auto type) { return total + GetAttributeSize(type); });
}

std::string_view GetAttributeTypeName(AttributeType type) {
  switch (type) {
#define ATTRIBUTE_TYPE(NAME, COMPONENTS, VERTEX)                                                                                           \
  case AttributeType::NAME:                                                                                                                \
    return #NAME;
#include "graphics_types.def"
  default:
    std::unreachable();
    break;
  }
}

// clang-format off
uint32_t GetDrawElementsTypeSize(DrawElementsType type) {
  switch (type) {
  case DrawElementsType::UNSIGNED_BYTE: return 1;
  case DrawElementsType::UNSIGNED_SHORT: return 2;
  case DrawElementsType::UNSIGNED_INT: return 4;
  default: std::unreachable(); break;
  }
}

uint32_t GetVertexAttributeSize(VertexAttributeType type) {
  switch (type) {
  case VertexAttributeType::BYTE:
  case VertexAttributeType::UNSIGNED_BYTE: return 1;
  case VertexAttributeType::SHORT:
  case VertexAttributeType::HALF_FLOAT:
  case VertexAttributeType::UNSIGNED_SHORT: return 2;
  case VertexAttributeType::FLOAT:
  case VertexAttributeType::FIXED:
  case VertexAttributeType::INT:
  case VertexAttributeType::UNSIGNED_INT:
  case VertexAttributeType::UNSIGNED_INT_10F_11F_11F_REV:
  case VertexAttributeType::UNSIGNED_INT_2_10_10_10_REV:
  case VertexAttributeType::INT_2_10_10_10_REV: return 4;
  case VertexAttributeType::DOUBLE: return 8;
  default: std::unreachable(); break;
  }
}

uint32_t GetVertexAttributeSize(VertexAttributeIntegerType type) {
  switch (type) {
  case VertexAttributeIntegerType::BYTE:
  case VertexAttributeIntegerType::UNSIGNED_BYTE: return 1;
  case VertexAttributeIntegerType::SHORT:
  case VertexAttributeIntegerType::UNSIGNED_SHORT: return 2;
  case VertexAttributeIntegerType::INT:
  case VertexAttributeIntegerType::UNSIGNED_INT: return 4;
  default: std::unreachable(); break;
  }
}

uint32_t GetVertexAttributeSize(VertexAttributeLongType type) {
  switch (type) {
  case VertexAttributeLongType::DOUBLE: return 8;
  default: std::unreachable(); break;
  }
}
// clang-format on

} // namespace Gloom
