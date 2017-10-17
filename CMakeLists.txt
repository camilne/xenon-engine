cmake_minimum_required(VERSION 3.7)
project(Xenon)

set(CMAKE_CXX_STANDARD 14)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE INCLUDES include/*.hpp)
file(GLOB_RECURSE SOURCES src/*.cpp)
set(SOURCE_FILES ${INCLUDES} ${SOURCES})
add_library(Xenon STATIC ${SOURCE_FILES})
target_include_directories(Xenon PUBLIC ${INCLUDE_DIR})

# Copy shaders
file(GLOB SHADERS "shaders/*")
file(COPY ${SHADERS} DESTINATION shaders)

# Opengl
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})

# GLFW
set(GLFW_DIR "${LIB_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("${GLFW_DIR}")
target_link_libraries(${PROJECT_NAME} "glfw" "${GLFW_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PUBLIC "${GLFW_DIR}/include")
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

# glad
set(GLAD_DIR "${LIB_DIR}/glad")
add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PUBLIC "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}")

# glm
include_directories(${LIB_DIR}/glm)

# examples
add_subdirectory(examples)

# tests
add_subdirectory(${LIB_DIR}/googletest/googletest)
enable_testing()
set(PROJECT_TEST_NAME Xenon_test)
include_directories(${LIB_DIR}/googletest/googletest/include)
file(GLOB_RECURSE TEST_SRC_FILES test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
target_link_libraries(${PROJECT_TEST_NAME} Xenon gtest)

add_test(test1 ${PROJECT_TEST_NAME})