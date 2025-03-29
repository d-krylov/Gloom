set(GLOOM_SOURCES
  ${PROJECT_SOURCE_DIR}/gloom/graphics/image.cpp
  ${PROJECT_SOURCE_DIR}/gloom/graphics/graphics_types.cpp
  ${PROJECT_SOURCE_DIR}/gloom/graphics/graphics_wrappers.cpp
  ${PROJECT_SOURCE_DIR}/gloom/mathematics/shapes.cpp
  ${PROJECT_SOURCE_DIR}/gloom/window/GLFW_window.cpp
  ${PROJECT_SOURCE_DIR}/gloom/common/gloom_tools.cpp
  ${PROJECT_SOURCE_DIR}/external/glad/glad.c
)

add_library(${PROJECT_NAME} STATIC ${GLOOM_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/external
  ${linalg_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} PUBLIC 
  OpenGL::GL
  glfw
)

target_compile_definitions(${PROJECT_NAME} PUBLIC GLOOM_PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")