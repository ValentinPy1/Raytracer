# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workdir/Epitech/2Tek/oop/raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workdir/Epitech/2Tek/oop/raytracer

# Include any dependencies generated for this target.
include CMakeFiles/ray.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ray.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ray.dir/flags.make

CMakeFiles/ray.dir/src/main.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/ray.dir/src/main.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workdir/Epitech/2Tek/oop/raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ray.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/main.cpp.o -MF CMakeFiles/ray.dir/src/main.cpp.o.d -o CMakeFiles/ray.dir/src/main.cpp.o -c /workdir/Epitech/2Tek/oop/raytracer/src/main.cpp

CMakeFiles/ray.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workdir/Epitech/2Tek/oop/raytracer/src/main.cpp > CMakeFiles/ray.dir/src/main.cpp.i

CMakeFiles/ray.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workdir/Epitech/2Tek/oop/raytracer/src/main.cpp -o CMakeFiles/ray.dir/src/main.cpp.s

CMakeFiles/ray.dir/src/Camera.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Camera.cpp.o: src/Camera.cpp
CMakeFiles/ray.dir/src/Camera.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workdir/Epitech/2Tek/oop/raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ray.dir/src/Camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Camera.cpp.o -MF CMakeFiles/ray.dir/src/Camera.cpp.o.d -o CMakeFiles/ray.dir/src/Camera.cpp.o -c /workdir/Epitech/2Tek/oop/raytracer/src/Camera.cpp

CMakeFiles/ray.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workdir/Epitech/2Tek/oop/raytracer/src/Camera.cpp > CMakeFiles/ray.dir/src/Camera.cpp.i

CMakeFiles/ray.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workdir/Epitech/2Tek/oop/raytracer/src/Camera.cpp -o CMakeFiles/ray.dir/src/Camera.cpp.s

CMakeFiles/ray.dir/src/Ray.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Ray.cpp.o: src/Ray.cpp
CMakeFiles/ray.dir/src/Ray.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workdir/Epitech/2Tek/oop/raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ray.dir/src/Ray.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Ray.cpp.o -MF CMakeFiles/ray.dir/src/Ray.cpp.o.d -o CMakeFiles/ray.dir/src/Ray.cpp.o -c /workdir/Epitech/2Tek/oop/raytracer/src/Ray.cpp

CMakeFiles/ray.dir/src/Ray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Ray.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workdir/Epitech/2Tek/oop/raytracer/src/Ray.cpp > CMakeFiles/ray.dir/src/Ray.cpp.i

CMakeFiles/ray.dir/src/Ray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Ray.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workdir/Epitech/2Tek/oop/raytracer/src/Ray.cpp -o CMakeFiles/ray.dir/src/Ray.cpp.s

CMakeFiles/ray.dir/src/Renderer.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Renderer.cpp.o: src/Renderer.cpp
CMakeFiles/ray.dir/src/Renderer.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workdir/Epitech/2Tek/oop/raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ray.dir/src/Renderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Renderer.cpp.o -MF CMakeFiles/ray.dir/src/Renderer.cpp.o.d -o CMakeFiles/ray.dir/src/Renderer.cpp.o -c /workdir/Epitech/2Tek/oop/raytracer/src/Renderer.cpp

CMakeFiles/ray.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workdir/Epitech/2Tek/oop/raytracer/src/Renderer.cpp > CMakeFiles/ray.dir/src/Renderer.cpp.i

CMakeFiles/ray.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workdir/Epitech/2Tek/oop/raytracer/src/Renderer.cpp -o CMakeFiles/ray.dir/src/Renderer.cpp.s

CMakeFiles/ray.dir/src/Logger.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Logger.cpp.o: src/Logger.cpp
CMakeFiles/ray.dir/src/Logger.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workdir/Epitech/2Tek/oop/raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ray.dir/src/Logger.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Logger.cpp.o -MF CMakeFiles/ray.dir/src/Logger.cpp.o.d -o CMakeFiles/ray.dir/src/Logger.cpp.o -c /workdir/Epitech/2Tek/oop/raytracer/src/Logger.cpp

CMakeFiles/ray.dir/src/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workdir/Epitech/2Tek/oop/raytracer/src/Logger.cpp > CMakeFiles/ray.dir/src/Logger.cpp.i

CMakeFiles/ray.dir/src/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workdir/Epitech/2Tek/oop/raytracer/src/Logger.cpp -o CMakeFiles/ray.dir/src/Logger.cpp.s

CMakeFiles/ray.dir/src/AObject.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/AObject.cpp.o: src/AObject.cpp
CMakeFiles/ray.dir/src/AObject.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workdir/Epitech/2Tek/oop/raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ray.dir/src/AObject.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/AObject.cpp.o -MF CMakeFiles/ray.dir/src/AObject.cpp.o.d -o CMakeFiles/ray.dir/src/AObject.cpp.o -c /workdir/Epitech/2Tek/oop/raytracer/src/AObject.cpp

CMakeFiles/ray.dir/src/AObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/AObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workdir/Epitech/2Tek/oop/raytracer/src/AObject.cpp > CMakeFiles/ray.dir/src/AObject.cpp.i

CMakeFiles/ray.dir/src/AObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/AObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workdir/Epitech/2Tek/oop/raytracer/src/AObject.cpp -o CMakeFiles/ray.dir/src/AObject.cpp.s

CMakeFiles/ray.dir/src/Intercection.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Intercection.cpp.o: src/Intercection.cpp
CMakeFiles/ray.dir/src/Intercection.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workdir/Epitech/2Tek/oop/raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ray.dir/src/Intercection.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Intercection.cpp.o -MF CMakeFiles/ray.dir/src/Intercection.cpp.o.d -o CMakeFiles/ray.dir/src/Intercection.cpp.o -c /workdir/Epitech/2Tek/oop/raytracer/src/Intercection.cpp

CMakeFiles/ray.dir/src/Intercection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Intercection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workdir/Epitech/2Tek/oop/raytracer/src/Intercection.cpp > CMakeFiles/ray.dir/src/Intercection.cpp.i

CMakeFiles/ray.dir/src/Intercection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Intercection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workdir/Epitech/2Tek/oop/raytracer/src/Intercection.cpp -o CMakeFiles/ray.dir/src/Intercection.cpp.s

CMakeFiles/ray.dir/src/operations.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/operations.cpp.o: src/operations.cpp
CMakeFiles/ray.dir/src/operations.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workdir/Epitech/2Tek/oop/raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ray.dir/src/operations.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/operations.cpp.o -MF CMakeFiles/ray.dir/src/operations.cpp.o.d -o CMakeFiles/ray.dir/src/operations.cpp.o -c /workdir/Epitech/2Tek/oop/raytracer/src/operations.cpp

CMakeFiles/ray.dir/src/operations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/operations.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workdir/Epitech/2Tek/oop/raytracer/src/operations.cpp > CMakeFiles/ray.dir/src/operations.cpp.i

CMakeFiles/ray.dir/src/operations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/operations.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workdir/Epitech/2Tek/oop/raytracer/src/operations.cpp -o CMakeFiles/ray.dir/src/operations.cpp.s

CMakeFiles/ray.dir/src/Light.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Light.cpp.o: src/Light.cpp
CMakeFiles/ray.dir/src/Light.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workdir/Epitech/2Tek/oop/raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ray.dir/src/Light.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Light.cpp.o -MF CMakeFiles/ray.dir/src/Light.cpp.o.d -o CMakeFiles/ray.dir/src/Light.cpp.o -c /workdir/Epitech/2Tek/oop/raytracer/src/Light.cpp

CMakeFiles/ray.dir/src/Light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Light.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workdir/Epitech/2Tek/oop/raytracer/src/Light.cpp > CMakeFiles/ray.dir/src/Light.cpp.i

CMakeFiles/ray.dir/src/Light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Light.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workdir/Epitech/2Tek/oop/raytracer/src/Light.cpp -o CMakeFiles/ray.dir/src/Light.cpp.s

CMakeFiles/ray.dir/src/Sphere.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Sphere.cpp.o: src/Sphere.cpp
CMakeFiles/ray.dir/src/Sphere.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workdir/Epitech/2Tek/oop/raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/ray.dir/src/Sphere.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Sphere.cpp.o -MF CMakeFiles/ray.dir/src/Sphere.cpp.o.d -o CMakeFiles/ray.dir/src/Sphere.cpp.o -c /workdir/Epitech/2Tek/oop/raytracer/src/Sphere.cpp

CMakeFiles/ray.dir/src/Sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Sphere.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workdir/Epitech/2Tek/oop/raytracer/src/Sphere.cpp > CMakeFiles/ray.dir/src/Sphere.cpp.i

CMakeFiles/ray.dir/src/Sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Sphere.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workdir/Epitech/2Tek/oop/raytracer/src/Sphere.cpp -o CMakeFiles/ray.dir/src/Sphere.cpp.s

CMakeFiles/ray.dir/src/Plane.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Plane.cpp.o: src/Plane.cpp
CMakeFiles/ray.dir/src/Plane.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workdir/Epitech/2Tek/oop/raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/ray.dir/src/Plane.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Plane.cpp.o -MF CMakeFiles/ray.dir/src/Plane.cpp.o.d -o CMakeFiles/ray.dir/src/Plane.cpp.o -c /workdir/Epitech/2Tek/oop/raytracer/src/Plane.cpp

CMakeFiles/ray.dir/src/Plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Plane.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workdir/Epitech/2Tek/oop/raytracer/src/Plane.cpp > CMakeFiles/ray.dir/src/Plane.cpp.i

CMakeFiles/ray.dir/src/Plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Plane.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workdir/Epitech/2Tek/oop/raytracer/src/Plane.cpp -o CMakeFiles/ray.dir/src/Plane.cpp.s

CMakeFiles/ray.dir/src/PluginManager.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/PluginManager.cpp.o: src/PluginManager.cpp
CMakeFiles/ray.dir/src/PluginManager.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workdir/Epitech/2Tek/oop/raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/ray.dir/src/PluginManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/PluginManager.cpp.o -MF CMakeFiles/ray.dir/src/PluginManager.cpp.o.d -o CMakeFiles/ray.dir/src/PluginManager.cpp.o -c /workdir/Epitech/2Tek/oop/raytracer/src/PluginManager.cpp

CMakeFiles/ray.dir/src/PluginManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/PluginManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workdir/Epitech/2Tek/oop/raytracer/src/PluginManager.cpp > CMakeFiles/ray.dir/src/PluginManager.cpp.i

CMakeFiles/ray.dir/src/PluginManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/PluginManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workdir/Epitech/2Tek/oop/raytracer/src/PluginManager.cpp -o CMakeFiles/ray.dir/src/PluginManager.cpp.s

CMakeFiles/ray.dir/src/Plugin.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Plugin.cpp.o: src/Plugin.cpp
CMakeFiles/ray.dir/src/Plugin.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workdir/Epitech/2Tek/oop/raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/ray.dir/src/Plugin.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Plugin.cpp.o -MF CMakeFiles/ray.dir/src/Plugin.cpp.o.d -o CMakeFiles/ray.dir/src/Plugin.cpp.o -c /workdir/Epitech/2Tek/oop/raytracer/src/Plugin.cpp

CMakeFiles/ray.dir/src/Plugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Plugin.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workdir/Epitech/2Tek/oop/raytracer/src/Plugin.cpp > CMakeFiles/ray.dir/src/Plugin.cpp.i

CMakeFiles/ray.dir/src/Plugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Plugin.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workdir/Epitech/2Tek/oop/raytracer/src/Plugin.cpp -o CMakeFiles/ray.dir/src/Plugin.cpp.s

CMakeFiles/ray.dir/src/DLLoader.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/DLLoader.cpp.o: src/DLLoader.cpp
CMakeFiles/ray.dir/src/DLLoader.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workdir/Epitech/2Tek/oop/raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/ray.dir/src/DLLoader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/DLLoader.cpp.o -MF CMakeFiles/ray.dir/src/DLLoader.cpp.o.d -o CMakeFiles/ray.dir/src/DLLoader.cpp.o -c /workdir/Epitech/2Tek/oop/raytracer/src/DLLoader.cpp

CMakeFiles/ray.dir/src/DLLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/DLLoader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workdir/Epitech/2Tek/oop/raytracer/src/DLLoader.cpp > CMakeFiles/ray.dir/src/DLLoader.cpp.i

CMakeFiles/ray.dir/src/DLLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/DLLoader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workdir/Epitech/2Tek/oop/raytracer/src/DLLoader.cpp -o CMakeFiles/ray.dir/src/DLLoader.cpp.s

CMakeFiles/ray.dir/src/Entity3D.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/Entity3D.cpp.o: src/Entity3D.cpp
CMakeFiles/ray.dir/src/Entity3D.cpp.o: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workdir/Epitech/2Tek/oop/raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/ray.dir/src/Entity3D.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/src/Entity3D.cpp.o -MF CMakeFiles/ray.dir/src/Entity3D.cpp.o.d -o CMakeFiles/ray.dir/src/Entity3D.cpp.o -c /workdir/Epitech/2Tek/oop/raytracer/src/Entity3D.cpp

CMakeFiles/ray.dir/src/Entity3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/Entity3D.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workdir/Epitech/2Tek/oop/raytracer/src/Entity3D.cpp > CMakeFiles/ray.dir/src/Entity3D.cpp.i

CMakeFiles/ray.dir/src/Entity3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/Entity3D.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workdir/Epitech/2Tek/oop/raytracer/src/Entity3D.cpp -o CMakeFiles/ray.dir/src/Entity3D.cpp.s

# Object files for target ray
ray_OBJECTS = \
"CMakeFiles/ray.dir/src/main.cpp.o" \
"CMakeFiles/ray.dir/src/Camera.cpp.o" \
"CMakeFiles/ray.dir/src/Ray.cpp.o" \
"CMakeFiles/ray.dir/src/Renderer.cpp.o" \
"CMakeFiles/ray.dir/src/Logger.cpp.o" \
"CMakeFiles/ray.dir/src/AObject.cpp.o" \
"CMakeFiles/ray.dir/src/Intercection.cpp.o" \
"CMakeFiles/ray.dir/src/operations.cpp.o" \
"CMakeFiles/ray.dir/src/Light.cpp.o" \
"CMakeFiles/ray.dir/src/Sphere.cpp.o" \
"CMakeFiles/ray.dir/src/Plane.cpp.o" \
"CMakeFiles/ray.dir/src/PluginManager.cpp.o" \
"CMakeFiles/ray.dir/src/Plugin.cpp.o" \
"CMakeFiles/ray.dir/src/DLLoader.cpp.o" \
"CMakeFiles/ray.dir/src/Entity3D.cpp.o"

# External object files for target ray
ray_EXTERNAL_OBJECTS =

ray: CMakeFiles/ray.dir/src/main.cpp.o
ray: CMakeFiles/ray.dir/src/Camera.cpp.o
ray: CMakeFiles/ray.dir/src/Ray.cpp.o
ray: CMakeFiles/ray.dir/src/Renderer.cpp.o
ray: CMakeFiles/ray.dir/src/Logger.cpp.o
ray: CMakeFiles/ray.dir/src/AObject.cpp.o
ray: CMakeFiles/ray.dir/src/Intercection.cpp.o
ray: CMakeFiles/ray.dir/src/operations.cpp.o
ray: CMakeFiles/ray.dir/src/Light.cpp.o
ray: CMakeFiles/ray.dir/src/Sphere.cpp.o
ray: CMakeFiles/ray.dir/src/Plane.cpp.o
ray: CMakeFiles/ray.dir/src/PluginManager.cpp.o
ray: CMakeFiles/ray.dir/src/Plugin.cpp.o
ray: CMakeFiles/ray.dir/src/DLLoader.cpp.o
ray: CMakeFiles/ray.dir/src/Entity3D.cpp.o
ray: CMakeFiles/ray.dir/build.make
ray: CMakeFiles/ray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workdir/Epitech/2Tek/oop/raytracer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable ray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ray.dir/build: ray
.PHONY : CMakeFiles/ray.dir/build

CMakeFiles/ray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ray.dir/clean

CMakeFiles/ray.dir/depend:
	cd /workdir/Epitech/2Tek/oop/raytracer && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workdir/Epitech/2Tek/oop/raytracer /workdir/Epitech/2Tek/oop/raytracer /workdir/Epitech/2Tek/oop/raytracer /workdir/Epitech/2Tek/oop/raytracer /workdir/Epitech/2Tek/oop/raytracer/CMakeFiles/ray.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ray.dir/depend

