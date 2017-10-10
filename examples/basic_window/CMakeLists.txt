cmake_minimum_required(VERSION 3.7)
project(basic_window)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(basic_window ${SOURCE_FILES})

target_link_libraries(basic_window LINK_PUBLIC Xenon)