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
    ../../LightModel.cpp
    )


# WRAPPER

add_library(Wrapper.v SHARED Wrapper.v.cpp Wrapper.v.entryPoint.cpp)
target_sources(Wrapper.v PRIVATE ${COMMON_SRC})



# LIGHTS

add_library(Directional.light.v SHARED ./Lights/Directional.light.v.cpp)
target_sources(Directional.light.v PRIVATE ${COMMON_SRC})

add_library(Disk.light.v SHARED ./Lights/Disk.light.v.cpp)
target_sources(Disk.light.v PRIVATE ${COMMON_SRC})



# PRIMITIVES

add_library(Sphere.primitive.v SHARED ./Primitives/Sphere.primitive.v.cpp)
target_sources(Sphere.primitive.v PRIVATE ${COMMON_SRC})

add_library(Plane.primitive.v SHARED ./Primitives/Plane.primitive.v.cpp)
target_sources(Plane.primitive.v PRIVATE ${COMMON_SRC})

add_library(Cercle.primitive.v SHARED ./Primitives/Cercle.primitive.v.cpp)
target_sources(Cercle.primitive.v PRIVATE ${COMMON_SRC})

add_library(Cylinder.primitive.v SHARED ./Primitives/Cylinder.primitive.v.cpp)
target_sources(Cylinder.primitive.v PRIVATE ${COMMON_SRC})

add_library(TrianglePart.primitive.v SHARED ./Primitives/TrianglePart.primitive.v.cpp)
target_sources(TrianglePart.primitive.v PRIVATE ${COMMON_SRC} ./Primitives/TrianglePart.entryPoint.cpp)

add_library(Mesh.primitive.v SHARED ./Primitives/Mesh.primitive.v.cpp)
target_sources(Mesh.primitive.v PRIVATE ${COMMON_SRC} ./Primitives/TrianglePart.primitive.v.cpp)

# MATERIALS

add_library(Flat.material.v SHARED ./Materials/Flat.material.v.cpp)
target_sources(Flat.material.v PRIVATE ${COMMON_SRC})

add_library(Check.material.v SHARED ./Materials/Check.material.v.cpp)
target_sources(Check.material.v PRIVATE ${COMMON_SRC})

add_library(Texture.material.v SHARED ./Materials/Texture.material.v.cpp)
target_sources(Texture.material.v PRIVATE ${COMMON_SRC})



# PROCESSES

add_library(ApplyIntersect.process.v SHARED ./Processes/ApplyIntersect.process.v.cpp)
target_sources(ApplyIntersect.process.v PRIVATE ${COMMON_SRC})

add_library(ApplyPointLights.process.v SHARED ./Processes/ApplyPointLights.process.v.cpp)
target_sources(ApplyPointLights.process.v PRIVATE ${COMMON_SRC})

add_library(ApplyReflections.process.v SHARED ./Processes/ApplyReflections.process.v.cpp)
target_sources(ApplyReflections.process.v PRIVATE ${COMMON_SRC})

add_library(ApplyAmbientOcclusion.process.v SHARED ./Processes/AmbientOcclusion.process.v.cpp)
target_sources(ApplyAmbientOcclusion.process.v PRIVATE ${COMMON_SRC})

add_library(Bloom.process.v SHARED ./Processes/Bloom.process.v.cpp)
target_sources(Bloom.process.v PRIVATE ${COMMON_SRC})

add_library(AmbientLight.process.v SHARED ./Processes/AmbientLight.process.v.cpp)
target_sources(AmbientLight.process.v PRIVATE ${COMMON_SRC})

# TARGET LINK LIB


target_link_libraries(
    Directional.light.v
    -lsfml-graphics
    -lsfml-system
    -lsfml-window
)

target_link_libraries(
    Bloom.process.v
    -lsfml-graphics
)

target_link_libraries(
    ApplyReflections.process.v
    Wrapper.v
)

target_link_libraries(
    ApplyReflections.process.v
    -lsfml-system
)

target_link_libraries(
    Disk.light.v
    -lsfml-system
)



# MOVE LIBS

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

add_custom_command(
    TARGET Directional.light.v POST_BUILD
    COMMAND mv libDirectional.light.v.so ..
)

add_custom_command(
    TARGET ApplyPointLights.process.v POST_BUILD
    COMMAND mv libApplyPointLights.process.v.so ..
)

add_dependencies(
    ApplyReflections.process.v
    Wrapper.v
)

add_custom_command(
    TARGET ApplyReflections.process.v POST_BUILD
    COMMAND mv libApplyReflections.process.v.so ..
)

add_custom_command(
    TARGET Disk.light.v POST_BUILD
    COMMAND mv libDisk.light.v.so ..
)

add_custom_command(
    TARGET Check.material.v POST_BUILD
    COMMAND mv libCheck.material.v.so ..
)

add_custom_command(
    TARGET ApplyAmbientOcclusion.process.v POST_BUILD
    COMMAND mv libApplyAmbientOcclusion.process.v.so ..
)

add_custom_command(
    TARGET Bloom.process.v POST_BUILD
    COMMAND mv libBloom.process.v.so ..
)

add_custom_command(
    TARGET Mesh.primitive.v POST_BUILD
    COMMAND mv libMesh.primitive.v.so ..
)

add_custom_command(
    TARGET AmbientLight.process.v POST_BUILD
    COMMAND mv libAmbientLight.process.v.so ..
)

add_custom_command(
    TARGET Texture.material.v POST_BUILD
    COMMAND mv libTexture.material.v.so ..
)
