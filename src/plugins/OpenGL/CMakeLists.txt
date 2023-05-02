cmake_minimum_required(VERSION 3.16.3)
cmake_policy(SET CMP0115 OLD)
project(testproject)
include_directories(
    ../../
    ../../plugins/
    ../../PluginManagement/
    ./
    ../
    )

set(COMMON_SRC
    ../../PluginManagement/PluginManager.cpp
    ../../PluginManagement/Plugin.cpp
    ../../PluginManagement/AMaterial.cpp
    ../../DLLoader.cpp
    ../../geometry.cpp
    ../../Renderer.cpp
    ../../Entity.cpp
)

add_compile_options(-Wall -Wextra -g3)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw)
find_package(OpenGL REQUIRED)

add_library(
    Wrapper.gl SHARED
    ${COMMON_SRC}
    Wrapper.gl.cpp
    ShaderPlugin
    glad/src/gl.c
    Opgl.cpp
    VBO
    SSBO
    ShaderProgram
)

target_link_libraries(
    Wrapper.gl
    -lm -lGLEW -lGL -lX11 -lpthread -lXrandr -lXi -ldl
)
target_link_libraries(Wrapper.gl glfw)
target_link_libraries(Wrapper.gl OpenGL::GL)

add_custom_command(
    TARGET Wrapper.gl POST_BUILD
    COMMAND cp libWrapper.gl.so ..
)

# PRIMITIVES

add_library(
    Triangle.primitive.gl SHARED
    Triangle.primitive.gl.cpp
    ${COMMON_SRC}
    TrianglePrimitiveHelper.gl.cpp
)

add_custom_command(
    TARGET Triangle.primitive.gl POST_BUILD
    COMMAND cp libTriangle.primitive.gl.so ..
)

# MATERIALS

add_library(
    Flat.material.gl SHARED
    FlatMaterial.gl.cpp
    ${COMMON_SRC}
)

add_custom_command(
    TARGET Flat.material.gl POST_BUILD
    COMMAND cp libFlat.material.gl.so ..
)
