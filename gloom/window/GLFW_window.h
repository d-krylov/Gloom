#ifndef GLOOM_GLFW_WINDOW_H
#define GLOOM_GLFW_WINDOW_H

#include <cstdint>
#include <string_view>

struct GLFWwindow;

namespace Gloom {

struct WindowSize {
  int32_t width_;
  int32_t height_;
};

class GLFWWindow {
public:
  GLFWWindow(std::string_view name, int32_t width, int32_t height, int32_t samples = 4);

  WindowSize GetSize() const;

  GLFWwindow *GetNativeWindow() const {
    return native_window_;
  }

  bool ShouldClose() const;

  void PollEvents();
  void Update();

private:
  GLFWwindow *native_window_{nullptr};
};

} // namespace Gloom

#endif // GLOOM_GLFW_WINDOW_H