set(GLOOM_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/graphics/image.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/graphics/graphics_types.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/graphics/graphics_wrappers.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/mathematics/shapes.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/window/GLFW_window.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/common/gloom_tools.cpp
)

add_library(${PROJECT_NAME} STATIC ${GLOOM_SOURCES})

add_library(linalg INTERFACE)
target_include_directories(linalg INTERFACE ${linalg_SOURCE_DIR})

target_include_directories(${PROJECT_NAME}
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  PUBLIC $<TARGET_PROPERTY:linalg,INTERFACE_INCLUDE_DIRECTORIES>
)

target_link_libraries(${PROJECT_NAME} PUBLIC 
  OpenGL::GL
  glfw
  glad
  linalg
)

target_compile_definitions(${PROJECT_NAME} PUBLIC GLOOM_PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")
