cmake_minimum_required(VERSION 3.16.3)
project(raytracer)
include_directories(
    src
    src/PluginManagement
    plugins
)
add_compile_options(-Wall -Wextra -O3)

add_executable (
    raytracer
    src/Renderer.cpp
    src/ConfigLoader.cpp
    src/PluginManagement/Plugin.cpp
    src/PluginManagement/PluginManager.cpp
    src/Entity.cpp
    src/Camera.cpp
    src/DLLoader.cpp
    src/main.cpp
    src/Ray.cpp
    src/operations.cpp
    src/geometry.cpp
    src/Intersection.cpp
)

target_link_libraries(
    raytracer
    -lsfml-graphics
    -lsfml-window
    -lsfml-system
    -lm
    -lconfig++
)

add_subdirectory(src/plugins/Vanille)
add_subdirectory(test)
# add_subdirectory(src/plugins/OpenGL)

