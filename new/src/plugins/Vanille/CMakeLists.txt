cmake_minimum_required(VERSION 3.16.3)
project(vanille)

include_directories(
    ../../
    ../../PluginManagement
    ../
)
add_compile_options(-Wall -Wextra -O3)

set(COMMON_SRC
    ../../PluginManagement/PluginManager.cpp
    ../../PluginManagement/Plugin.cpp
    ../../DLLoader.cpp
    ../../Intersection.cpp
    ../../geometry.cpp
    ../../Renderer.cpp
)

add_library(
    Wrapper.v SHARED
    ${COMMON_SRC}
    Wrapper.v.cpp
)
