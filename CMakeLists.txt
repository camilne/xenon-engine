cmake_minimum_required(VERSION 3.7)
project(Xenon)

option(examples "Build the example programs" OFF)

set(CMAKE_CXX_STANDARD 14)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set(SOURCE_FILES library.cpp library.h)
add_library(Xenon ${SOURCE_FILES})

# GLFW
set(GLFW_DIR "${LIB_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("${GLFW_DIR}")
target_link_libraries(${PROJECT_NAME} "glfw" "${GLFW_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

# glad
set(GLAD_DIR "${LIB_DIR}/glad")
add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}")

#if(examples)
#    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/examples)
#endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set(BASIC_WINDOW_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/examples/basic_window/main.cpp)
add_executable(XenonBasicWindow ${BASIC_WINDOW_SOURCE_FILES})

target_include_directories(XenonBasicWindow PRIVATE ${GLFW_DIR}/include)
target_include_directories(XenonBasicWindow PRIVATE ${GLAD_DIR}/include)
target_link_libraries(XenonBasicWindow Xenon glfw glad)