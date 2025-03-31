cmake_minimum_required(VERSION 3.25)

project(Gloom LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

include(cmake/cpm.cmake)

CPMAddPackage(
  NAME linalg
  GITHUB_REPOSITORY sgorsten/linalg
  GIT_TAG main
)

if(${PROJECT_IS_TOP_LEVEL})

  set(CMAKE_BUILD_TYPE Debug)
  
  include(cmake/clang_format.cmake)

  add_clang_format_target(format "build;external")

  add_subdirectory(examples)

else()
  
  set(CMAKE_BUILD_TYPE Release)

endif()

add_subdirectory(external)
add_subdirectory(gloom)