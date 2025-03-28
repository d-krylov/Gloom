set(GLOOM_EXAMPLES
  triangle
  texture
  framebuffer
)

foreach(exe ${GLOOM_EXAMPLES})
  add_executable(${exe} ${CMAKE_CURRENT_SOURCE_DIR}/${exe}/${exe}.cpp)
  target_link_libraries(${exe} PRIVATE Gloom)
endforeach()