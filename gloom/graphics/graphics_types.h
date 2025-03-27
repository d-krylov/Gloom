#ifndef GRAPHICS_TYPES_H
#define GRAPHICS_TYPES_H

#include "glad/glad.h"
#include "gloom/common/gloom_concepts.h"

namespace Gloom {

using Descriptor = GLuint;

enum class ErrorCode {
#define ERROR_CODE(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class ShaderType : GLenum {
#define SHADER_TYPE(NAME) NAME = GL_##NAME##_SHADER,
#include "graphics_types.def"
};

enum class ProgramProperty {
#define PROGRAM_PROPERTY(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class ShaderParameterName {
#define SHADER_PARAMETER_NAME(NAME) NAME = GL_##NAME,
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

enum class BufferStorageMask : GLenum {
#define BUFFER_STORAGE_MASK(NAME) NAME = GL_##NAME,
#include "graphics_types.def"
};

enum class MapBufferAccessMask : GLenum {
#define MAP_BUFFER_ACCESS_MASK(NAME) NAME = GL_MAP_##NAME,
#include "graphics_types.def"
};

enum class BufferStorageTarget : GLenum {
#define BUFFER_STORAGE_TARGET(NAME) NAME = GL_##NAME,
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
#define INTERNAL_FORMAT(NAME, BASE) NAME = GL_##NAME,
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

ALLOW_BITMASK_ENUM(ClearBufferMask);
ALLOW_BITMASK_ENUM(BufferStorageMask);
ALLOW_BITMASK_ENUM(MapBufferAccessMask);
ALLOW_BITMASK_ENUM(MemoryBarrierMask);
ALLOW_BITMASK_ENUM(MemoryBarrierRegionMask);

uint32_t GetRGBA(uint32_t red, uint32_t green, uint32_t blue, uint32_t alpha);

} // namespace Gloom

#endif // GRAPHICS_TYPES_H