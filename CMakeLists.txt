cmake_minimum_required(VERSION 3.7)
project(Xenon)

set(CMAKE_CXX_STANDARD 14)

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})

# GLEW
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/glew/build/cmake)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/glfw)

set(SOURCE_FILES library.cpp library.h)
add_library(Xenon ${SOURCE_FILES})

#target_include_directories(Xenon ${OPENGL_INCLUDE_DIR})
target_link_libraries(Xenon ${OPENGL_gl_LIBRARY} glfw)