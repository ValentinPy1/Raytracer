cmake_minimum_required(VERSION 3.16.3)
project(vanille)

include_directories(
    ../../
    ../../PluginManagement
    ../
    ./
)
add_compile_options(-Wall -Wextra -O3 -g3)

set(COMMON_SRC
    ../../PluginManagement/PluginManager.cpp
    ../../PluginManagement/Plugin.cpp
    ../../DLLoader.cpp
    ../../Intersection.cpp
    ../../geometry.cpp
    ../../Renderer.cpp
    ../../Camera.cpp
    ../../Ray.cpp
)

add_library(
    Wrapper.v SHARED
    ${COMMON_SRC}
    Wrapper.v.cpp
)

add_library(
    Sphere.primitive.v SHARED
    ${COMMON_SRC}
    Sphere.primitive.v.cpp
)

add_library(
    Flat.material.v SHARED
    ${COMMON_SRC}
    Flat.material.v.cpp
)

add_custom_command(
    TARGET Sphere.primitive.v POST_BUILD
    COMMAND cp *.so ..
)
# add_library(
#     Lighting.process.v SHARED
#     ${COMMON_SRC}
#     Lighting.process.v.cpp
# )
