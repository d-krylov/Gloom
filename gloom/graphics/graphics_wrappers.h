#ifndef GRAPHICS_WRAPPERS_H
#define GRAPHICS_WRAPPERS_H

#include "gloom/graphics/graphics_types.h"
#include "gloom/mathematics/mathematics_types.h"
#include <string>
#include <span>

namespace Gloom {

ErrorCode GetError();
void Enable(Capabilities capability);
void Disable(Capabilities capability);
void SetStencilOperation(StencilOperation fail, StencilOperation zfail, StencilOperation zpass);
void SetStencilFunction(ComparisonFunction function, int32_t reference, uint32_t mask);
void SetBlendFunctionSeparate(BlendingFactor srgb, BlendingFactor drgb, BlendingFactor salpha, BlendingFactor dalpha);
void Clear(ClearBufferMask mask);
void SetClearColor(float r, float g, float b, float a);
void SetDebugMessageCallback(GLDEBUGPROC callback);
void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height);
void SetScissor(int32_t x, int32_t y, int32_t w, int32_t h);
void SetPatchParameter(PatchParameterName patch_parameter, int32_t value);
void SetPolygonMode(PolygonMode mode);
void SetBlendEquation(BlendEquationMode mode);
void DepthMask(bool enable_write);
void FrontFace(FrontFaceDirection direction);
void CullFace(TriangleFace triangle_face);

// VERTEX ARRAY
void BindVertexArray(Descriptor &vertex_array);
void CreateVertexArray(Descriptor &vertex_array);
void DeleteVertexArray(Descriptor &vertex_array);
void EnableVertexArrayAttribute(Descriptor &vertex_array, uint32_t index);
void SetVertexArrayBindingDivisor(Descriptor &vertex_array, uint32_t binding_index, uint32_t divisor);
void SetVertexArrayVertexBuffer(Descriptor &vertex_array, Descriptor &buffer, uint32_t binding, int32_t stride, int64_t offset);
void SetVertexArrayElementBuffer(Descriptor &vertex_array, Descriptor &buffer);
void SetAttributeBinding(Descriptor &vao, uint32_t attribute_index, uint32_t binding_index);
void SetAttributeFormat(Descriptor &vao, uint32_t index, int32_t size, VertexAttributeType type, uint32_t offset, bool normalized);
void SetAttributeFormat(Descriptor &vao, uint32_t index, int32_t size, VertexAttributeIntegerType type, uint32_t offset);
void SetAttributeFormat(Descriptor &vao, uint32_t index, int32_t size, VertexAttributeLongType type, uint32_t offset);

// BUFFER
void CreateBuffer(Descriptor &buffer);
void CreateBuffers(std::span<Descriptor> buffers);
void BindBuffer(Descriptor &buffer, BufferStorageTarget target);
void CreateEmptyBufferStorage(Descriptor &buffer, BufferStorageMask storage_mask, int64_t size);
bool UnmapBuffer(Descriptor &buffer);
void DeleteBuffer(Descriptor &buffer);
void FlushBuffer(Descriptor &buffer, uint64_t offset, uint64_t length);
void CopyBuffer(Descriptor &source, Descriptor &destination, int64_t source_offset, int64_t destination_offset, int64_t size);
void GetBufferParameter(Descriptor &buffer, BufferParameterName parameter_name, int64_t &result);

// PROGRAM
Descriptor CreateProgram();
Descriptor CreateShader(ShaderType shader_type);
void UseProgram(Descriptor &program);
void LinkProgram(Descriptor &program);
void DeleteProgram(Descriptor &program);
void CompileShader(Descriptor &shader);
void AttachShader(Descriptor &program, Descriptor &shader);
void ShaderSource(Descriptor &shader, std::string_view sources);
void DeleteShader(Descriptor &shader);
void DispatchCompute(uint32_t num_groups_x, uint32_t num_groups_y, uint32_t num_groups_z);
void GetShaderParameter(Descriptor &shader, ShaderParameterName parameter, int32_t &result);
void GetProgramParameter(Descriptor &program, ProgramProperty property, int32_t &result);
void GetProgramInterface(Descriptor &program, ProgramInterface program_interface, ProgramInterfaceParameterName name, int32_t &result);
void SetUniform(int32_t location, float value);
void SetUniform(int32_t location, int32_t value);
void SetUniform(int32_t location, uint32_t value);
void SetUniform(int32_t location, float v0, float v1);
void SetUniform(int32_t location, float v0, float v1, float v2);
void SetUniform(int32_t location, float v0, float v1, float v2, float v3);
void SetUniform(int32_t location, int32_t v0, int32_t v1);
void SetUniform(int32_t location, int32_t v0, int32_t v1, int32_t v2);
void SetUniform(int32_t location, int32_t v0, int32_t v1, int32_t v2, int32_t v3);
void SetUniform(int32_t location, uint32_t v0, uint32_t v1);
void SetUniform(int32_t location, uint32_t v0, uint32_t v1, uint32_t v2);
void SetUniform(int32_t location, uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3);
void SetUniform(int32_t location, const Vector2f &value);
void SetUniform(int32_t location, const Vector2i &value);
void SetUniform(int32_t location, const Vector2u &value);
void SetUniform(int32_t location, const Vector3f &value);
void SetUniform(int32_t location, const Vector3i &value);
void SetUniform(int32_t location, const Vector3u &value);
void SetUniform(int32_t location, const Vector4f &value);
void SetUniform(int32_t location, const Vector4i &value);
void SetUniform(int32_t location, const Vector4u &value);
void SetUniform(int32_t location, const Matrix4f &value, bool transpose);
int32_t GetUniformLocation(Descriptor &program, std::string_view name);
std::string GetProgramResourceName(Descriptor &program, ProgramInterface interface, uint32_t index, uint32_t name_size);
std::vector<int32_t> GetProgramResource(Descriptor &program, ProgramInterface interface, uint32_t index,
                                        std::span<const ProgramResourceProperty> properties);

// TEXTURE
void DeleteTexture(Descriptor &texture);
void BindTextureUnit(Descriptor &texture, uint32_t unit);
void CreateTexture(Descriptor &texture, TextureTarget target);
void CreateTextureStorage(Descriptor &texture, int32_t levels, int32_t width, InternalFormat format);
void CreateTextureStorage(Descriptor &texture, int32_t levels, int32_t width, int32_t height, InternalFormat format);
void CreateTextureStorage(Descriptor &texture, int32_t levels, int32_t width, int32_t height, int32_t depth, InternalFormat format);
void BindImageTexture(Descriptor &texture, uint32_t unit, int32_t level, uint32_t layer, BufferAccess access, InternalFormat format);
void BindImageTexture(Descriptor &texture, uint32_t unit, int32_t level, BufferAccess access, InternalFormat format);
void GenerateTextureMipmap(Descriptor &texture);
void SetTextureParameter(Descriptor &texture, TextureParameterName parameter, int32_t value);
uint64_t GetTextureHandle(Descriptor &texture);

// SAMPLER
void CreateSampler(Descriptor &sampler);
void DeleteSampler(Descriptor &sampler);
void BindSampler(Descriptor &sampler, uint32_t unit);

// FRAMEBUFFER
void CreateFramebuffer(Descriptor &framebuffer);
void DeleteFramebuffer(Descriptor &framebuffer);
void BindFramebuffer(Descriptor &framebuffer, FramebufferTarget framebuffer_target);
void FramebufferAttach(Descriptor &framebuffer, Descriptor &texture, FramebufferAttachment point, int32_t level);
void FramebufferAttach(Descriptor &framebuffer, Descriptor &renderbuffer, FramebufferAttachment point, RenderbufferTarget target);
void FramebufferAttach(Descriptor &framebuffer, Descriptor &texture, FramebufferAttachment point, int32_t level, int32_t layer);
FramebufferStatus CheckFramebufferStatus(Descriptor &framebuffer, FramebufferTarget framebuffer_target);

// RENDERBUFFER
void CreateRenderbuffer(Descriptor &renderbuffer);
void DeleteRenderbuffer(Descriptor &renderbuffer);
void BindRenderbuffer(Descriptor &renderbuffer);
void UnbindFramebuffer(FramebufferTarget framebuffer_target);
void CreateRenderbufferStorage(Descriptor &renderbuffer, InternalFormat format, int32_t width, int32_t height);
void CreateRenderbufferStorageMultisample(Descriptor &renderbuffer, InternalFormat format, int32_t width, int32_t height, int32_t samples);

// DRAW
void DrawArrays(int32_t first, int32_t count, PrimitiveType primitive_type);
void DrawElements(int32_t first, int32_t count, int64_t indices, DrawElementsType index_type, PrimitiveType primitive_type);
void DrawElementsBaseVertex(int32_t count, int64_t indices, int32_t base, DrawElementsType index_type, PrimitiveType primitive_type);
void DrawArraysInstanced(int32_t indices, int32_t instances, int32_t first, PrimitiveType primitive_type);
void DrawArraysIndirect(int64_t commands_offset_in_bytes, PrimitiveType primitive_type);

// BARRIER
void MemoryBarrier(MemoryBarrierMask barrier_mask);
void MemoryBarrierByRegion(MemoryBarrierRegionMask barrier_mask);

} // namespace Gloom

#include "graphics_wrappers.ipp"

#endif // GRAPHICS_WRAPPERS_H