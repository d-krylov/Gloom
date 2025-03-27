#ifndef GRAPHICS_WRAPPERS_IPP
#define GRAPHICS_WRAPPERS_IPP

#include <span>

namespace Gloom {

template <typename F, typename... ARGS> decltype(auto) GL_CALL(F &&function, ARGS &&...arguments) {
  if constexpr (std::is_void_v<std::invoke_result_t<F, ARGS...>>) {
    std::forward<F>(function)(std::forward<ARGS>(arguments)...);
  } else {
    auto result = std::forward<F>(function)(std::forward<ARGS>(arguments)...);
    return result;
  }
}

template <typename... T> inline void Enable(T... capabilities) {
  (Enable(capabilities), ...);
}

template <typename... T> inline void Disable(T... capabilities) {
  (Disable(capabilities), ...);
}

template <typename... T> inline void CompileShaders(T &...shaders) {
  (CompileShader(shaders), ...);
}

template <typename... T> inline void AttachShaders(Descriptor program, T &...shaders) {
  (AttachShader(program, shaders), ...);
}

template <typename T = std::byte> inline T *MapBuffer(Descriptor &buffer, int64_t offset, int64_t size, MapBufferAccessMask map_access) {
  auto mapped_buffer = GL_CALL(glMapNamedBufferRange, buffer, offset, size, std::to_underlying(map_access));
  return static_cast<T *>(mapped_buffer);
}

template <StandardLayout T> inline void SetBufferData(Descriptor &buffer, std::span<const T> buffer_data, int64_t offset) {
  GL_CALL(glNamedBufferSubData, buffer, offset, buffer_data.size_bytes(), buffer_data.data());
}

template <StandardLayout T> void CreateBufferStorage(Descriptor &buffer, BufferStorageMask storage_mask, std::span<const T> buffer_data) {
  GL_CALL(glNamedBufferStorage, buffer, buffer_data.size_bytes(), buffer_data.data(), std::to_underlying(storage_mask));
}

template <StandardLayout T>
inline void TextureSubImage(Descriptor &texture, int32_t width, PixelFormat format, PixelType type, std::span<const T> data,
                            int32_t xoffset, int32_t level) {
  GL_CALL(glTextureSubImage1D, texture, level, xoffset, width, std::to_underlying(format), std::to_underlying(type), data.data());
}

template <StandardLayout T>
inline void TextureSubImage(Descriptor &texture, int32_t width, int32_t height, PixelFormat format, PixelType type, std::span<const T> data,
                            int32_t xoffset, int32_t yoffset, int32_t level) {
  GL_CALL(glTextureSubImage2D, texture, level, xoffset, yoffset, width, height, std::to_underlying(format), std::to_underlying(type),
          data.data());
}

template <StandardLayout T>
inline void TextureSubImage(Descriptor &texture, int32_t width, int32_t height, int32_t depth, PixelFormat format, PixelType type,
                            std::span<const T> data, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t level) {
  GL_CALL(glTextureSubImage3D, texture, level, xoffset, yoffset, zoffset, width, height, depth, std::to_underlying(format),
          std::to_underlying(type), data.data());
}

} // namespace Gloom

#endif // GRAPHICS_WRAPPERS_IPP