cmake_minimum_required(VERSION 3.16.3)
project(testproject)
include_directories(./include)
add_compile_options(-Wall -Wextra)
add_executable (
    ray
    src/main.cpp
    src/Camera.cpp
    src/Ray.cpp
    src/Renderer.cpp
    src/Logger.cpp
    src/AObject.cpp
    src/Intercection.cpp
    src/operations.cpp
    src/Light.cpp
    src/Sphere.cpp
    src/Plane.cpp
    src/PluginManager.cpp
    src/Plugin.cpp
    src/DLLoader.cpp
    src/Entity3D.cpp
    src/ConfigLoader.cpp
)
target_link_libraries(
    ray
    -lsfml-graphics
    -lsfml-window
    -lsfml-system
    -lm
    -lconfig++
)
