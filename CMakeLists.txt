cmake_minimum_required(VERSION 3.25)

project(Gloom LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

include(cmake/clang_format.cmake)

add_clang_format_target(format "build;external")

set(CMAKE_BUILD_TYPE RelWithDebInfo)

add_subdirectory(gloom)
add_subdirectory(examples)