#ifndef GRAPHICS_TYPES_H
#define GRAPHICS_TYPES_H

#include "external/glad/glad.h"
#include "gloom/common/gloom_concepts.h"
#include <string>
#include <span>

namespace Gloom {

using Descriptor = GLuint;

// DEBUG

enum class ErrorCode : GLenum {
#define ERROR_CODE(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class DebugSource : GLenum {
#define DEBUG_SOURCE(NAME) NAME = GL_DEBUG_SOURCE_##NAME,
#include "graphics_types.def"
};

enum class DebugType : GLenum {
#define DEBUG_TYPEE(NAME) NAME = GL_DEBUG_TYPE_##NAME,
#include "graphics_types.def"
};

enum class DebugSeverity : GLenum {
#define DEBUG_SEVERITY(NAME) NAME = GL_DEBUG_SEVERITY_##NAME,
#include "graphics_types.def"
};

// PROGRAM

enum class ShaderType : GLenum {
#define SHADER_TYPE(NAME) NAME = GL_##NAME##_SHADER,
#include "graphics_types.def"
};

enum class ProgramProperty : GLenum {
#define PROGRAM_PROPERTY(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class ShaderParameterName : GLenum {
#define SHADER_PARAMETER_NAME(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class ProgramInterface : GLenum {
#define PROGRAM_INTERFACE(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class ProgramInterfaceParameterName : GLenum {
#define PROGRAM_INTERFACE_PARAMETER_NAME(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class ProgramResourceProperty : GLenum {
#define PROGRAM_RESOURCE_PROPERTY(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class ComparisonFunction : GLenum {
#define COMPARISON_FUNCTION(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class StencilOperation : GLenum {
#define STENCIL_OPERATION(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class PixelFormat {
#define PIXEL_FORMAT(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class PixelType {
#define PIXEL_TYPE(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class BlendingFactor {
#define BLENDING_FACTOR(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class BlendEquationMode {
#define BLEND_EQUATION_MODE(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class Capabilities : GLenum {
#define CAPABILITIES(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class PolygonMode {
#define POLYGON_MODE(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

// BUFFER

enum class BufferStorageMask : GLenum {
#define BUFFER_STORAGE_MASK(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class MapBufferAccessMask : GLenum {
#define MAP_BUFFER_ACCESS_MASK(NAME) NAME = GL_MAP_##NAME,
#include "graphics_types.def"
};

enum class BufferAccess {
#define BUFFER_ACCESS(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class BufferStorageTarget : GLenum {
#define BUFFER_STORAGE_TARGET(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class BufferParameterName : GLenum {
#define BUFFER_PARAMETER_NAME(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class BufferTarget : GLenum {
#define BUFFER_TARGET(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class TextureTarget : GLenum {
#define TEXTURE_TARGET(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class InternalFormat : GLenum {
#define INTERNAL_FORMAT(NAME, BASE, R, G, B, A) NAME = GL_##NAME,
#include "graphics_types.def"
};

// FRAMEBUFFER

enum class FramebufferAttachment : GLenum {
#define FRAMEBUFFER_ATTACHMENT(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class FramebufferTarget : GLenum {
#define FRAMEBUFFER_TARGET(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class FramebufferStatus {
#define FRAMEBUFFER_STATUS(NAME) NAME = GL_FRAMEBUFFER_##NAME,
#include "graphics_types.def"
};

enum class RenderbufferTarget : GLenum {
#define RENDERBUFFER_TARGET(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

// TEXTURE

enum class TextureWrapMode : GLenum {
#define TEXTURE_WRAP_MODE(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class TextureParameterName : GLenum {
#define TEXTURE_PARAMETER_NAME(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class TextureMinFilter : GLenum {
#define MIN_FILTER(X) X = GL_##X,
#include "graphics_types.def"
};

enum class TextureMagFilter : GLenum {
#define MAG_FILTER(X) X = GL_##X,
#include "graphics_types.def"
};

// VERTEX ARRAY

enum class VertexAttributeType : GLenum {
#define VERTEX_ATTRIBUTE_TYPE(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class VertexAttributeIntegerType : GLenum {
#define VERTEX_ATTRIBUTE_INTEGER_TYPE(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class VertexAttributeLongType : GLenum {
#define VERTEX_ATTRIBUTE_LONG_TYPE(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class AttributeType : GLenum {
#define ATTRIBUTE_TYPE(NAME, COMPONENTS, VERTEX) NAME = GL_##NAME,
#include "graphics_types.def"
};

// DRAW

enum class DrawElementsType {
#define DRAW_ELEMENTS_TYPE(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class PrimitiveType : GLenum {
#define PRIMITIVE_TYPE(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class ClearBufferMask {
#define CLEAR_BUFFER_MASK(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class MemoryBarrierMask : GLenum {
#define MEMORY_BARRIER_MASK(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class MemoryBarrierRegionMask : GLenum {
#define MEMORY_BARRIER_REGION_MASK(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class TriangleFace : GLenum {
#define TRIANGLE_FACE(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class PatchParameterName : GLenum {
#define PATCH_PARAMETER_NAME(NAME) NAME = GL_PATCH_##NAME,
#include "graphics_types.def"
};

enum class FrontFaceDirection : GLenum {
#define PATCH_PARAMETERFRONT_FACE_DIRECTION_NAME(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

ALLOW_BITMASK_ENUM(ClearBufferMask);
ALLOW_BITMASK_ENUM(BufferStorageMask);
ALLOW_BITMASK_ENUM(MapBufferAccessMask);
ALLOW_BITMASK_ENUM(MemoryBarrierMask);
ALLOW_BITMASK_ENUM(MemoryBarrierRegionMask);

struct DrawArraysIndirectCommand {
  uint32_t count;
  uint32_t instance_count;
  uint32_t first;
  uint32_t base_instance;
};

struct DrawElementsIndirectCommand {
  uint32_t count;
  uint32_t instance_count;
  uint32_t first_index;
  int32_t base_vertex;
  uint32_t base_instance;
};

struct FormatInformation {
  PixelFormat pixel_format_;
};

struct AttributeInformation {
  uint32_t components_;
  VertexAttributeType vertex_attribute_type_;
};

uint32_t GetDrawElementsTypeSize(DrawElementsType type);
uint32_t GetVertexAttributeSize(VertexAttributeIntegerType type);
uint32_t GetVertexAttributeSize(VertexAttributeType type);
uint32_t GetVertexAttributeSize(VertexAttributeLongType type);
uint32_t GetStride(std::span<const AttributeType> types);
uint32_t GetAttributeSize(AttributeType type);

AttributeInformation GetAttributeInformation(AttributeType type);
std::string_view GetAttributeTypeName(AttributeType type);

template <ScopedEnum Enum> auto Cast(Enum type) {
  return std::to_underlying(type);
}

} // namespace Gloom

#endif // GRAPHICS_TYPES_H
