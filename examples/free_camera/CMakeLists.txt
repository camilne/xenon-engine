cmake_minimum_required(VERSION 3.7)
project(free_camera)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Application.cpp Application.hpp)
add_executable(XenonFreeCamera ${SOURCE_FILES})

target_link_libraries(XenonFreeCamera LINK_PUBLIC Xenon)

configure_file(free_camera.vs free_camera.vs COPYONLY)
configure_file(free_camera.fs free_camera.fs COPYONLY)