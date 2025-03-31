set(GLAD_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/glad/glad.c
)

add_library(glad ${GLAD_SOURCES})

target_include_directories(glad
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)