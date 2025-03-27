#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "GLFW_window.h"

namespace Gloom {

GLFWWindow::GLFWWindow(std::string_view name, int32_t w, int32_t h, int32_t samples) {
  auto status = glfwInit();

  if (status != GLFW_TRUE) {
  }

  glfwWindowHint(GLFW_SAMPLES, samples);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  native_window_ = glfwCreateWindow(w, h, name.data(), nullptr, nullptr);

  if (native_window_ == nullptr) {
  }

  glfwMakeContextCurrent(native_window_);

  status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

  if (status == false) {
  }

  glfwSetWindowUserPointer(native_window_, this);
}

bool GLFWWindow::ShouldClose() const {
  return glfwWindowShouldClose(native_window_);
}

void GLFWWindow::PollEvents() {
  glfwPollEvents();
}

void GLFWWindow::Update() {
  glfwSwapBuffers(native_window_);
}

WindowSize GLFWWindow::GetSize() const {
  WindowSize window_size;
  glfwGetWindowSize(native_window_, &window_size.width_, &window_size.height_);
  return window_size;
}

} // namespace Gloom
