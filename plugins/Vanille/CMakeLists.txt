cmake_minimum_required(VERSION 3.16.3)
project(vanille)
include_directories(../../include)
add_compile_options(-Wall -Wextra -O3 -g3)
add_library (
    pluginWrapper.v
    ../../src/PluginManager.cpp
    ../../src/Plugin.cpp
    ../../src/DLLoader.cpp
    Wrapper.v.cpp
)

target_link_libraries(
    pluginWrapper.v
    -lm -lpthread
)

set_target_properties(
    pluginWrapper.v
    PROPERTIES COMPILE_FLAGS "-fPIC -shared -Wall -Wextra -O3 -g3"
)
