#include "graphics_wrappers.h"

namespace Gloom {

ErrorCode GetError() {
  auto status = GL_CALL(glGetError);
  return static_cast<ErrorCode>(status);
}

void SetDebugMessageCallback(GLDEBUGPROC callback) {
  GL_CALL(glDebugMessageCallback, callback, nullptr);
}

void Enable(Capabilities capability) {
  GL_CALL(glEnable, Cast(capability));
}

void Disable(Capabilities capability) {
  GL_CALL(glDisable, Cast(capability));
}

void SetStencilOperation(StencilOperation fail, StencilOperation zfail, StencilOperation zpass) {
  GL_CALL(glStencilOp, Cast(fail), Cast(zfail), Cast(zpass));
}

void SetStencilFunction(ComparisonFunction function, int32_t reference, uint32_t mask) {
  GL_CALL(glStencilFunc, Cast(function), reference, mask);
}

void SetBlendFunctionSeparate(BlendingFactor srgb, BlendingFactor drgb, BlendingFactor salpha, BlendingFactor dalpha) {
  GL_CALL(glBlendFuncSeparate, Cast(srgb), Cast(drgb), Cast(salpha), Cast(dalpha));
}

void SetBlendEquation(BlendEquationMode mode) {
  GL_CALL(glBlendEquation, Cast(mode));
}

void Clear(ClearBufferMask mask) {
  GL_CALL(glClear, Cast(mask));
}

void SetClearColor(float r, float g, float b, float a) {
  GL_CALL(glClearColor, r, g, b, a);
}

void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height) {
  GL_CALL(glViewport, x, y, width, height);
}

void SetScissor(int32_t x, int32_t y, int32_t w, int32_t h) {
  GL_CALL(glScissor, x, y, w, h);
}

void SetPolygonMode(PolygonMode mode) {
  GL_CALL(glPolygonMode, Cast(TriangleFace::FRONT_AND_BACK), Cast(mode));
}

void SetPatchParameter(PatchParameterName patch_parameter, int32_t value) {
  GL_CALL(glPatchParameteri, Cast(patch_parameter), value);
}

void DepthMask(bool enable_write) {
  GL_CALL(glDepthMask, enable_write);
}

void FrontFace(FrontFaceDirection direction) {
  GL_CALL(glFrontFace, Cast(direction));
}

void CullFace(TriangleFace triangle_face) {
  GL_CALL(glCullFace, Cast(triangle_face));
}

// TEXTURE

void CreateTexture(Descriptor &texture, TextureTarget target) {
  GL_CALL(glCreateTextures, Cast(target), 1, &texture);
}

void DeleteTexture(Descriptor &texture) {
  GL_CALL(glDeleteTextures, 1, &texture);
}

void BindTextureUnit(Descriptor &texture, uint32_t unit) {
  GL_CALL(glBindTextureUnit, unit, texture);
}

void CreateTextureStorage(Descriptor &texture, int32_t levels, int32_t width, InternalFormat format) {
  GL_CALL(glTextureStorage1D, texture, levels, Cast(format), width);
}

void CreateTextureStorage(Descriptor &texture, int32_t levels, int32_t width, int32_t height, InternalFormat format) {
  GL_CALL(glTextureStorage2D, texture, levels, Cast(format), width, height);
}

void CreateTextureStorage(Descriptor &texture, int32_t levels, int32_t width, int32_t height, int32_t depth, InternalFormat format) {
  GL_CALL(glTextureStorage3D, texture, levels, Cast(format), width, height, depth);
}

void GenerateTextureMipmap(Descriptor &texture) {
  GL_CALL(glGenerateTextureMipmap, texture);
}

void SetTextureParameter(Descriptor &texture, TextureParameterName parameter, int32_t value) {
  GL_CALL(glTextureParameteri, texture, Cast(parameter), value);
}

void BindImageTexture(Descriptor &texture, uint32_t unit, int32_t level, uint32_t layer, BufferAccess access, InternalFormat format) {
  GL_CALL(glBindImageTexture, unit, texture, level, true, layer, Cast(access), Cast(format));
}

void BindImageTexture(Descriptor &texture, uint32_t unit, int32_t level, BufferAccess access, InternalFormat format) {
  GL_CALL(glBindImageTexture, unit, texture, level, false, 0, Cast(access), Cast(format));
}

uint64_t GetTextureHandle(Descriptor &texture) {
  return GL_CALL(glGetTextureHandleARB, texture);
}

// SAMPLER

void CreateSampler(Descriptor &sampler) {
  GL_CALL(glCreateSamplers, 1, &sampler);
}

void DeleteSampler(Descriptor &sampler) {
  GL_CALL(glDeleteSamplers, 1, &sampler);
}

void BindSampler(Descriptor &sampler, uint32_t unit) {
  GL_CALL(glBindSampler, unit, sampler);
}

// BUFFER

void CreateBuffer(Descriptor &buffer) {
  GL_CALL(glCreateBuffers, 1, &buffer);
}

void CreateBuffers(std::span<Descriptor> buffers) {
  GL_CALL(glCreateBuffers, buffers.size(), buffers.data());
}

void DeleteBuffer(Descriptor &buffer) {
  GL_CALL(glDeleteBuffers, 1, &buffer);
}

void CreateEmptyBufferStorage(Descriptor &buffer, BufferStorageMask storage_mask, int64_t size) {
  GL_CALL(glNamedBufferStorage, buffer, size, nullptr, Cast(storage_mask));
}

void BindBuffer(Descriptor &buffer, BufferStorageTarget target) {
  GL_CALL(glBindBuffer, Cast(target), buffer);
}

void BindBufferBase(Descriptor &buffer, BufferTarget target, uint32_t index) {
  GL_CALL(glBindBufferBase, Cast(target), index, buffer);
}

void FlushBuffer(Descriptor &buffer, uint64_t offset, uint64_t length) {
  GL_CALL(glFlushMappedNamedBufferRange, buffer, offset, length);
}

void CopyBuffer(Descriptor &source, Descriptor &destination, int64_t source_offset, int64_t destination_offset, int64_t size) {
  GL_CALL(glCopyNamedBufferSubData, source, destination, source_offset, destination_offset, size);
}

void GetBufferParameter(Descriptor &buffer, BufferParameterName parameter_name, int64_t &result) {
  GL_CALL(glGetNamedBufferParameteri64v, buffer, Cast(parameter_name), &result);
}

bool UnmapBuffer(Descriptor &buffer) {
  auto result = GL_CALL(glUnmapNamedBuffer, buffer);
  return result;
}

// PROGRAM

Descriptor CreateProgram() {
  return GL_CALL(glCreateProgram);
}

Descriptor CreateShader(ShaderType shader_type) {
  return GL_CALL(glCreateShader, Cast(shader_type));
}

void UseProgram(Descriptor &program) {
  GL_CALL(glUseProgram, program);
}

void LinkProgram(Descriptor &program) {
  GL_CALL(glLinkProgram, program);
}

void DeleteProgram(Descriptor &program) {
  GL_CALL(glDeleteProgram, program);
}

void CompileShader(Descriptor &shader) {
  GL_CALL(glCompileShader, shader);
}

void ShaderSource(Descriptor &shader, const char *sources) {
  GL_CALL(glShaderSource, shader, 1, &sources, nullptr);
}

void ShaderSource(Descriptor &shader, std::string_view sources) {
  ShaderSource(shader, sources.data());
}

void DeleteShader(Descriptor &shader) {
  GL_CALL(glDeleteShader, shader);
}

void AttachShader(Descriptor &program, Descriptor &shader) {
  GL_CALL(glAttachShader, program, shader);
}

void DispatchCompute(uint32_t num_groups_x, uint32_t num_groups_y, uint32_t num_groups_z) {
  GL_CALL(glDispatchCompute, num_groups_x, num_groups_y, num_groups_z);
}

void GetShaderParameter(Descriptor &shader, ShaderParameterName parameter, int32_t &result) {
  GL_CALL(glGetShaderiv, shader, Cast(parameter), &result);
}

void GetProgramParameter(Descriptor &program, ProgramProperty property, int32_t &result) {
  GL_CALL(glGetProgramiv, program, Cast(property), &result);
}

void GetProgramInterface(Descriptor &program, ProgramInterface program_interface, ProgramInterfaceParameterName name, int32_t &result) {
  GL_CALL(glGetProgramInterfaceiv, program, Cast(program_interface), Cast(name), &result);
}

std::vector<int32_t> GetProgramResource(Descriptor &program, ProgramInterface interface, uint32_t index,
                                        std::span<const ProgramResourceProperty> properties) {
  auto size = properties.size();
  auto result = std::vector<int32_t>(size);
  GL_CALL(glGetProgramResourceiv, program, Cast(interface), index, size, (const GLenum *)properties.data(), size, nullptr, result.data());
  return result;
}

std::string GetProgramResourceName(Descriptor &program, ProgramInterface interface, uint32_t index, uint32_t name_size) {
  std::string name(name_size, ' ');
  GL_CALL(glGetProgramResourceName, program, Cast(interface), index, name_size, nullptr, name.data());
  return name;
}

int32_t GetUniformLocation(Descriptor &program, std::string_view name) {
  return GL_CALL(glGetUniformLocation, program, name.data());
}

void SetUniform(int32_t location, float value) {
  GL_CALL(glUniform1f, location, value);
}

void SetUniform(int32_t location, int32_t value) {
  GL_CALL(glUniform1i, location, value);
}

void SetUniform(int32_t location, uint32_t value) {
  GL_CALL(glUniform1ui, location, value);
}

void SetUniform(int32_t location, float v0, float v1) {
  GL_CALL(glUniform2f, location, v0, v1);
}

void SetUniform(int32_t location, float v0, float v1, float v2) {
  GL_CALL(glUniform3f, location, v0, v1, v2);
}

void SetUniform(int32_t location, float v0, float v1, float v2, float v3) {
  GL_CALL(glUniform4f, location, v0, v1, v2, v3);
}

void SetUniform(int32_t location, int32_t v0, int32_t v1) {
  GL_CALL(glUniform2i, location, v0, v1);
}

void SetUniform(int32_t location, int32_t v0, int32_t v1, int32_t v2) {
  GL_CALL(glUniform3i, location, v0, v1, v2);
}

void SetUniform(int32_t location, int32_t v0, int32_t v1, int32_t v2, int32_t v3) {
  GL_CALL(glUniform4i, location, v0, v1, v2, v3);
}

void SetUniform(int32_t location, uint32_t v0, uint32_t v1) {
  GL_CALL(glUniform2ui, location, v0, v1);
}

void SetUniform(int32_t location, uint32_t v0, uint32_t v1, uint32_t v2) {
  GL_CALL(glUniform3ui, location, v0, v1, v2);
}

void SetUniform(int32_t location, uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3) {
  GL_CALL(glUniform4ui, location, v0, v1, v2, v3);
}

void SetUniform(int32_t location, const Vector2f &value) {
  GL_CALL(glUniform2fv, location, 1, (const float *)&value);
}

void SetUniform(int32_t location, const Vector3f &value) {
  GL_CALL(glUniform3fv, location, 1, (const float *)&value);
}

void SetUniform(int32_t location, const Vector4f &value) {
  GL_CALL(glUniform4fv, location, 1, (const float *)&value);
}

void SetUniform(int32_t location, const Vector2i &value) {
  GL_CALL(glUniform2iv, location, 1, (const int32_t *)&value);
}

void SetUniform(int32_t location, const Vector3i &value) {
  GL_CALL(glUniform3iv, location, 1, (const int32_t *)&value);
}

void SetUniform(int32_t location, const Vector4i &value) {
  GL_CALL(glUniform4iv, location, 1, (const int32_t *)&value);
}

void SetUniform(int32_t location, const Vector2u &value) {
  GL_CALL(glUniform2uiv, location, 1, (const uint32_t *)&value);
}

void SetUniform(int32_t location, const Vector3u &value) {
  GL_CALL(glUniform3uiv, location, 1, (const uint32_t *)&value);
}

void SetUniform(int32_t location, const Vector4u &value) {
  GL_CALL(glUniform4uiv, location, 1, (const uint32_t *)&value);
}

void SetUniform(int32_t location, const Matrix4f &value, bool transpose) {
  GL_CALL(glUniformMatrix4fv, location, 1, transpose, (const float *)&value);
}

// FRAMEBUFFER

void CreateFramebuffer(Descriptor &framebuffer) {
  GL_CALL(glCreateFramebuffers, 1, &framebuffer);
}

void UnbindFramebuffer(FramebufferTarget framebuffer_target) {
  GL_CALL(glBindFramebuffer, Cast(framebuffer_target), 0u);
}

void BindFramebuffer(Descriptor &framebuffer, FramebufferTarget framebuffer_target) {
  GL_CALL(glBindFramebuffer, Cast(framebuffer_target), framebuffer);
}

void FramebufferAttach(Descriptor &framebuffer, Descriptor &texture, FramebufferAttachment point, int32_t level) {
  GL_CALL(glNamedFramebufferTexture, framebuffer, Cast(point), texture, level);
}

void FramebufferAttach(Descriptor &framebuffer, Descriptor &renderbuffer, FramebufferAttachment point, RenderbufferTarget target) {
  GL_CALL(glNamedFramebufferRenderbuffer, framebuffer, Cast(point), Cast(target), renderbuffer);
}

void FramebufferAttach(Descriptor &framebuffer, Descriptor &texture, FramebufferAttachment point, int32_t level, int32_t layer) {
  GL_CALL(glNamedFramebufferTextureLayer, framebuffer, Cast(point), texture, level, layer);
}

void DeleteFramebuffer(Descriptor &framebuffer) {
  GL_CALL(glDeleteFramebuffers, 1, &framebuffer);
}

FramebufferStatus CheckFramebufferStatus(Descriptor &framebuffer, FramebufferTarget framebuffer_target) {
  auto status = GL_CALL(glCheckNamedFramebufferStatus, framebuffer, Cast(framebuffer_target));
  return static_cast<FramebufferStatus>(status);
}

// RENDERBUFFER

void CreateRenderbuffer(Descriptor &renderbuffer) {
  GL_CALL(glCreateRenderbuffers, 1, &renderbuffer);
}

void DeleteRenderbuffer(Descriptor &renderbuffer) {
  GL_CALL(glDeleteRenderbuffers, 1, &renderbuffer);
}

void BindRenderbuffer(Descriptor &renderbuffer) {
  GL_CALL(glBindRenderbuffer, Cast(RenderbufferTarget::RENDERBUFFER), renderbuffer);
}

void CreateRenderbufferStorage(Descriptor &renderbuffer, InternalFormat format, int32_t width, int32_t height) {
  GL_CALL(glNamedRenderbufferStorage, renderbuffer, Cast(format), width, height);
}

void CreateRenderbufferStorageMultisample(Descriptor &renderbuffer, InternalFormat format, int32_t width, int32_t height, int32_t samples) {
  GL_CALL(glNamedRenderbufferStorageMultisample, renderbuffer, samples, Cast(format), width, height);
}

// VERTEX ARRAY

void CreateVertexArray(Descriptor &vao) {
  GL_CALL(glCreateVertexArrays, 1, &vao);
}

void DeleteVertexArray(Descriptor &vao) {
  GL_CALL(glDeleteVertexArrays, 1, &vao);
}

void BindVertexArray(Descriptor &vao) {
  GL_CALL(glBindVertexArray, vao);
}

void EnableVertexArrayAttribute(Descriptor &vao, uint32_t index) {
  GL_CALL(glEnableVertexArrayAttrib, vao, index);
}

void SetVertexArrayBindingDivisor(Descriptor &vao, uint32_t binding_index, uint32_t divisor) {
  GL_CALL(glVertexArrayBindingDivisor, vao, binding_index, divisor);
}

void SetVertexArrayVertexBuffer(Descriptor &vao, Descriptor &buffer, uint32_t binding, int32_t stride, int64_t offset) {
  GL_CALL(glVertexArrayVertexBuffer, vao, binding, buffer, offset, stride);
}

void SetVertexArrayElementBuffer(Descriptor &vao, Descriptor &buffer) {
  GL_CALL(glVertexArrayElementBuffer, vao, buffer);
}

void SetAttributeBinding(Descriptor &vao, uint32_t attribute_index, uint32_t binding_index) {
  GL_CALL(glVertexArrayAttribBinding, vao, attribute_index, binding_index);
}

void SetAttributeFormat(Descriptor &vao, uint32_t index, int32_t size, VertexAttributeType type, uint32_t offset, bool normalized) {
  GL_CALL(glVertexArrayAttribFormat, vao, index, size, Cast(type), GLboolean(normalized), offset);
}

void SetAttributeFormat(Descriptor &vao, uint32_t index, int32_t size, VertexAttributeIntegerType type, uint32_t offset) {
  GL_CALL(glVertexArrayAttribIFormat, vao, index, size, Cast(type), offset);
}

void SetAttributeFormat(Descriptor &vao, uint32_t index, int32_t size, VertexAttributeLongType type, uint32_t offset) {
  GL_CALL(glVertexArrayAttribLFormat, vao, index, size, Cast(type), offset);
}

// DRAW

void DrawArrays(int32_t first, int32_t count, PrimitiveType primitive_type) {
  GL_CALL(glDrawArrays, Cast(primitive_type), first, count);
}

void DrawArraysInstanced(int32_t indices, int32_t instances, int32_t first, PrimitiveType primitive_type) {
  GL_CALL(glDrawArraysInstanced, Cast(primitive_type), first, indices, instances);
}

void DrawElements(int32_t first, int32_t count, int64_t indices_in_bytes, DrawElementsType index_type, PrimitiveType primitive_type) {
  GL_CALL(glDrawElements, Cast(primitive_type), count, Cast(index_type), (const void *)indices_in_bytes);
}

void DrawElementsBaseVertex(int32_t count, int64_t indices, int32_t base, DrawElementsType index_type, PrimitiveType primitive_type) {
  GL_CALL(glDrawElementsBaseVertex, Cast(primitive_type), count, Cast(index_type), (const void *)indices, base);
}

void DrawArraysIndirect(int64_t commands_offset_in_bytes, PrimitiveType primitive_type) {
  GL_CALL(glDrawArraysIndirect, Cast(primitive_type), (const void *)commands_offset_in_bytes);
}

// BARRIER

void MemoryBarrier(MemoryBarrierMask barrier_mask) {
  GL_CALL(glMemoryBarrier, Cast(barrier_mask));
}

void MemoryBarrierByRegion(MemoryBarrierRegionMask barrier_mask) {
  GL_CALL(glMemoryBarrierByRegion, Cast(barrier_mask));
}

} // namespace Gloom
