cmake_minimum_required(VERSION 3.16.3)

project(Vanille)

include_directories(
    ../../include
    ../../include/plugins
    ../../include/plugins/Vanille
)

add_compile_options(-Wall -Wextra -O3 -g3)

set(COMMON_SRC
    ../../src/PluginManager.cpp
    ../../src/Plugin.cpp
    ../../src/DLLoader.cpp
)

add_library (
    pluginWrapper.v SHARED
    ${COMMON_SRC}
    Wrapper.v.cpp
)

add_library (
    Sphere.primitive.v SHARED
    ${COMMON_SRC}
    Sphere.primitive.v.cpp
)

add_library (
    Lighting.process.v SHARED
    ${COMMON_SRC}
    Lighting.process.v.cpp
)

add_library (
    Flat.texture.v SHARED
    ${COMMON_SRC}
    Flat.texture.v.cpp
)

target_link_libraries(
    pluginWrapper.v
    -lm -lpthread -lsfml-graphics -lsfml-window -lsfml-system
)

set_target_properties(
    pluginWrapper.v
    PROPERTIES COMPILE_FLAGS "-fPIC -shared -Wall -Wextra -O3 -g3"
)
