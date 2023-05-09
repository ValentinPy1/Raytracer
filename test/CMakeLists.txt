cmake_minimum_required(VERSION 3.16.3)
project(raytracer)
include_directories(
    ../src
    ../src/PluginManagement
    ../plugins
)

add_executable(
    unit_tests
    ../src/Ray.cpp
    ../src/operations.cpp
    ../src/geometry.cpp
    ../src/Intersection.cpp
    ../src/Entity.cpp
    ../src/Camera.cpp
    testMath.cpp
)
target_link_libraries(unit_tests -lcriterion -lsfml-system -lsfml-graphics -lm)
