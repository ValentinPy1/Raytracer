cmake_minimum_required(VERSION 3.16.3)
project(testproject)
include_directories(../../include)
add_compile_options(-Wall -Wextra -O3 -g3)
add_executable (
    pluginOpenGL
    opgl_main_test.cpp
    PluginOpenGL.cpp
    PluginShader.gl.cpp
    ../../src/PluginManager.cpp
    ../../src/Plugin.cpp
    ../../src/DLLoader.cpp
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

add_library(PluginSpherePrimitive.gl SHARED
    PluginSpherePrimitive.gl.cpp
    glad/src/gl.c
    PluginShader.gl.cpp
    ../../src/PluginManager.cpp
    ../../src/Plugin.cpp
    ../../src/DLLoader.cpp
)

target_link_libraries(
    PluginSpherePrimitive.gl
    -lm -lGLEW -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lconfig++
)

set_target_properties(
    PluginSpherePrimitive.gl
    PROPERTIES COMPILE_FLAGS "-fPIC -shared -Wall -Wextra -O3 -g3"
)

target_link_libraries(PluginSpherePrimitive.gl glfw)
target_link_libraries(PluginSpherePrimitive.gl OpenGL::GL)

add_custom_command(TARGET PluginSpherePrimitive.gl POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:PluginSpherePrimitive.gl> ${CMAKE_CURRENT_SOURCE_DIR}/../
)
