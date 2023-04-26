cmake_minimum_required(VERSION 3.16.3)
project(vanille)

include_directories(
    ../../
    ../../PluginManagement/
    ../
    ./
)

add_compile_options(-Wall -Wextra -O3 -g3)

set(COMMON_SRC
    ../../PluginManagement/PluginManager.cpp
    ../../PluginManagement/Plugin.cpp
    ../../PluginManagement/AMaterial.cpp
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
    Cercle.primitive.v SHARED
    ${COMMON_SRC}
    Cercle.primitive.v.cpp
)

add_library(
    Cylinder.primitive.v SHARED
    ${COMMON_SRC}
    Cylinder.primitive.v.cpp
)

add_library(
    Flat.material.v SHARED
    ${COMMON_SRC}
    Flat.material.v.cpp
)

add_custom_command(
    TARGET Wrapper.v POST_BUILD
    COMMAND mv libWrapper.v.so ..
)

add_custom_command(
    TARGET Sphere.primitive.v POST_BUILD
    COMMAND mv libSphere.primitive.v.so ..
)

add_custom_command(
    TARGET Flat.material.v POST_BUILD
    COMMAND mv libFlat.material.v.so ..
)
