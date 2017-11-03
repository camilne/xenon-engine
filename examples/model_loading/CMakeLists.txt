cmake_minimum_required(VERSION 3.7)
project(model_loading)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Application.cpp Application.hpp)
add_executable(XenonModelLoading ${SOURCE_FILES})

target_link_libraries(XenonModelLoading LINK_PUBLIC Xenon)

configure_file(model_loading.vs model_loading.vs COPYONLY)
configure_file(model_loading.fs model_loading.fs COPYONLY)

# copy model
file(COPY TARDIS DESTINATION ./)