cmake_minimum_required(VERSION 3.16.3)
project(testproject)
include_directories(../../include)
add_compile_options(-Wall -Wextra -O3 -g3)
add_executable (
    pluginOpenGL
    main.cpp
    glad/src/gl.c
)
target_link_libraries(
    pluginOpenGL
    -lm -lGLEW -lGL -lX11 -lpthread -lXrandr -lXi -ldl
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw)
find_package(OpenGL REQUIRED)

target_link_libraries(pluginOpenGL glfw)
target_link_libraries(pluginOpenGL OpenGL::GL)
