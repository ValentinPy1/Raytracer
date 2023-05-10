cmake_minimum_required(VERSION 3.16.3)
project(raytracer)
include_directories(
    ../src
    ../src/PluginManagement
    ../plugins
)
add_compile_options(-Wall -Wextra -O3)

add_executable(
    unit_tests
    ../src/Ray.cpp
    ../src/operations.cpp
    ../src/geometry.cpp
    ../src/Intersection.cpp
    ../src/Camera.cpp
    ../src/Entity.cpp
    test_virtualOD.cpp
)

target_link_libraries(
    unit_tests
    -lcriterion
    -lsfml-graphics
)
