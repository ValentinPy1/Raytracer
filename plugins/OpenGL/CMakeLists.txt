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

add_library (
    PluginOpenGL.gl SHARED
    PluginOpenGL.cpp
    PluginShader.gl.cpp
    ../../src/PluginManager.cpp
    ../../src/Plugin.cpp
    ../../src/DLLoader.cpp
    glad/src/gl.c
)
target_link_libraries(
    PluginOpenGL.gl
    -lm -lGLEW -lGL -lX11 -lpthread -lXrandr -lXi -ldl
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw)
find_package(OpenGL REQUIRED)

target_link_libraries(pluginOpenGL glfw)
target_link_libraries(pluginOpenGL OpenGL::GL)
target_link_libraries(PluginOpenGL.gl glfw)
target_link_libraries(PluginOpenGL.gl OpenGL::GL)

add_library(SpherePrimitive.gl SHARED
    SpherePrimitive.gl.cpp
    glad/src/gl.c
    PluginShader.gl.cpp
    ../../src/PluginManager.cpp
    ../../src/Plugin.cpp
    ../../src/DLLoader.cpp
    ../../src/Entity.cpp
)

target_link_libraries(
    SpherePrimitive.gl
    -lm -lGLEW -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lconfig++
)

set_target_properties(
    SpherePrimitive.gl
    PROPERTIES COMPILE_FLAGS "-fPIC -shared -Wall -Wextra -O3 -g3"
)

target_link_libraries(SpherePrimitive.gl glfw)
target_link_libraries(SpherePrimitive.gl OpenGL::GL)


add_library(
    Wrapper.gl SHARED
    Wrapper.gl.cpp
    ../../src/PluginManager.cpp
    ../../src/Plugin.cpp
    ../../src/DLLoader.cpp
)

target_link_libraries(Wrapper.gl -lconfig++ PluginOpenGL.gl)

add_custom_command(TARGET SpherePrimitive.gl POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:SpherePrimitive.gl> ${CMAKE_CURRENT_SOURCE_DIR}/../

)

