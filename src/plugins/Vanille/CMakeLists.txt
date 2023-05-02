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
    ../../operations.cpp
    ../../Entity.cpp
)

add_library(
    Wrapper.v SHARED
    ${COMMON_SRC}
    Wrapper.v.cpp
)

add_library(AmbientLight.v SHARED
    ${COMMON_SRC}
    AmbientLight.v.cpp
)

add_library(
    Sphere.primitive.v SHARED
    ${COMMON_SRC}
    Sphere.primitive.v.cpp
)

add_library(
    Plane.primitive.v SHARED
    ${COMMON_SRC}
    Plane.primitive.v.cpp
)

target_link_libraries(
    Sphere.primitive.v
    -lsfml-graphics
    -lsfml-system
    -lsfml-window
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

add_library(ApplyIntersect.process.v SHARED
    ${COMMON_SRC}
    ApplyIntersect.process.v.cpp
    ../../Entity.cpp
)

add_custom_command(
    TARGET Wrapper.v POST_BUILD
    COMMAND cp libWrapper.v.so ..
)

add_custom_command(
    TARGET ApplyIntersect.process.v POST_BUILD
    COMMAND mv libApplyIntersect.process.v.so ..
)

add_custom_command(
    TARGET Sphere.primitive.v POST_BUILD
    COMMAND mv libSphere.primitive.v.so ..
)

add_custom_command(
    TARGET Plane.primitive.v POST_BUILD
    COMMAND mv libPlane.primitive.v.so ..
)

add_custom_command(
    TARGET Flat.material.v POST_BUILD
    COMMAND mv libFlat.material.v.so ..
)

add_library(
    Directional.light.v SHARED
    ${COMMON_SRC}
    Directional.light.v.cpp
    ../../LightModel.cpp
    ../../Entity.cpp
    ../../operations.cpp
)

target_link_libraries(
    Directional.light.v
    -lsfml-graphics
    -lsfml-system
    -lsfml-window
)

add_custom_command(
    TARGET Directional.light.v POST_BUILD
    COMMAND mv libDirectional.light.v.so ..
)

add_library(
    ApplyPointLights.process.v SHARED
    ${COMMON_SRC}
    applyPointLights.process.v.cpp
)

target_link_libraries(
    ApplyPointLights.process.v
    -lsfml-graphics
    -lsfml-system
    -lsfml-window
)

add_custom_command(
    TARGET ApplyPointLights.process.v POST_BUILD
    COMMAND mv libApplyPointLights.process.v.so ..
)

add_library(
    ApplyReflections.process.v SHARED
    ${COMMON_SRC}
    ApplyReflections.process.v.cpp
    ../../Camera.cpp
    ../../Entity.cpp
)

add_dependencies(
    ApplyReflections.process.v
    Wrapper.v
)

target_link_libraries(
    ApplyReflections.process.v
    Wrapper.v
)

target_link_libraries(
    ApplyReflections.process.v
    -lsfml-system
)

add_custom_command(
    TARGET ApplyReflections.process.v POST_BUILD
    COMMAND mv libApplyReflections.process.v.so ..
)


add_library(
    Disk.light.v SHARED
    ${COMMON_SRC}
    Disk.light.v.cpp
    ../../Entity.cpp
    ../../operations.cpp
    ../../LightModel.cpp
)

target_link_libraries(
    Disk.light.v
    -lsfml-system
)

add_custom_command(
    TARGET Disk.light.v POST_BUILD
    COMMAND mv libDisk.light.v.so ..
)
