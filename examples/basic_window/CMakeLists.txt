cmake_minimum_required(VERSION 3.7)
project(basic_window)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(XenonBasicWindow ${SOURCE_FILES})

target_link_libraries(XenonBasicWindow LINK_PUBLIC Xenon)