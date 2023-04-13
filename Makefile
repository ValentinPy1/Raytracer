# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/Amour/Documents/Epitech/Tech2/raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/Amour/Documents/Epitech/Tech2/raytracer

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/Amour/Documents/Epitech/Tech2/raytracer/CMakeFiles /home/Amour/Documents/Epitech/Tech2/raytracer//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/Amour/Documents/Epitech/Tech2/raytracer/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named ray

# Build rule for target.
ray: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 ray
.PHONY : ray

# fast build rule for target.
ray/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/build
.PHONY : ray/fast

src/AObject.o: src/AObject.cpp.o
.PHONY : src/AObject.o

# target to build an object file
src/AObject.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/AObject.cpp.o
.PHONY : src/AObject.cpp.o

src/AObject.i: src/AObject.cpp.i
.PHONY : src/AObject.i

# target to preprocess a source file
src/AObject.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/AObject.cpp.i
.PHONY : src/AObject.cpp.i

src/AObject.s: src/AObject.cpp.s
.PHONY : src/AObject.s

# target to generate assembly for a file
src/AObject.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/AObject.cpp.s
.PHONY : src/AObject.cpp.s

src/Camera.o: src/Camera.cpp.o
.PHONY : src/Camera.o

# target to build an object file
src/Camera.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Camera.cpp.o
.PHONY : src/Camera.cpp.o

src/Camera.i: src/Camera.cpp.i
.PHONY : src/Camera.i

# target to preprocess a source file
src/Camera.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Camera.cpp.i
.PHONY : src/Camera.cpp.i

src/Camera.s: src/Camera.cpp.s
.PHONY : src/Camera.s

# target to generate assembly for a file
src/Camera.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Camera.cpp.s
.PHONY : src/Camera.cpp.s

src/Intercection.o: src/Intercection.cpp.o
.PHONY : src/Intercection.o

# target to build an object file
src/Intercection.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Intercection.cpp.o
.PHONY : src/Intercection.cpp.o

src/Intercection.i: src/Intercection.cpp.i
.PHONY : src/Intercection.i

# target to preprocess a source file
src/Intercection.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Intercection.cpp.i
.PHONY : src/Intercection.cpp.i

src/Intercection.s: src/Intercection.cpp.s
.PHONY : src/Intercection.s

# target to generate assembly for a file
src/Intercection.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Intercection.cpp.s
.PHONY : src/Intercection.cpp.s

src/Light.o: src/Light.cpp.o
.PHONY : src/Light.o

# target to build an object file
src/Light.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Light.cpp.o
.PHONY : src/Light.cpp.o

src/Light.i: src/Light.cpp.i
.PHONY : src/Light.i

# target to preprocess a source file
src/Light.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Light.cpp.i
.PHONY : src/Light.cpp.i

src/Light.s: src/Light.cpp.s
.PHONY : src/Light.s

# target to generate assembly for a file
src/Light.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Light.cpp.s
.PHONY : src/Light.cpp.s

src/Logger.o: src/Logger.cpp.o
.PHONY : src/Logger.o

# target to build an object file
src/Logger.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Logger.cpp.o
.PHONY : src/Logger.cpp.o

src/Logger.i: src/Logger.cpp.i
.PHONY : src/Logger.i

# target to preprocess a source file
src/Logger.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Logger.cpp.i
.PHONY : src/Logger.cpp.i

src/Logger.s: src/Logger.cpp.s
.PHONY : src/Logger.s

# target to generate assembly for a file
src/Logger.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Logger.cpp.s
.PHONY : src/Logger.cpp.s

src/Plane.o: src/Plane.cpp.o
.PHONY : src/Plane.o

# target to build an object file
src/Plane.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Plane.cpp.o
.PHONY : src/Plane.cpp.o

src/Plane.i: src/Plane.cpp.i
.PHONY : src/Plane.i

# target to preprocess a source file
src/Plane.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Plane.cpp.i
.PHONY : src/Plane.cpp.i

src/Plane.s: src/Plane.cpp.s
.PHONY : src/Plane.s

# target to generate assembly for a file
src/Plane.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Plane.cpp.s
.PHONY : src/Plane.cpp.s

src/Ray.o: src/Ray.cpp.o
.PHONY : src/Ray.o

# target to build an object file
src/Ray.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Ray.cpp.o
.PHONY : src/Ray.cpp.o

src/Ray.i: src/Ray.cpp.i
.PHONY : src/Ray.i

# target to preprocess a source file
src/Ray.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Ray.cpp.i
.PHONY : src/Ray.cpp.i

src/Ray.s: src/Ray.cpp.s
.PHONY : src/Ray.s

# target to generate assembly for a file
src/Ray.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Ray.cpp.s
.PHONY : src/Ray.cpp.s

src/Renderer.o: src/Renderer.cpp.o
.PHONY : src/Renderer.o

# target to build an object file
src/Renderer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Renderer.cpp.o
.PHONY : src/Renderer.cpp.o

src/Renderer.i: src/Renderer.cpp.i
.PHONY : src/Renderer.i

# target to preprocess a source file
src/Renderer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Renderer.cpp.i
.PHONY : src/Renderer.cpp.i

src/Renderer.s: src/Renderer.cpp.s
.PHONY : src/Renderer.s

# target to generate assembly for a file
src/Renderer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Renderer.cpp.s
.PHONY : src/Renderer.cpp.s

src/Sphere.o: src/Sphere.cpp.o
.PHONY : src/Sphere.o

# target to build an object file
src/Sphere.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Sphere.cpp.o
.PHONY : src/Sphere.cpp.o

src/Sphere.i: src/Sphere.cpp.i
.PHONY : src/Sphere.i

# target to preprocess a source file
src/Sphere.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Sphere.cpp.i
.PHONY : src/Sphere.cpp.i

src/Sphere.s: src/Sphere.cpp.s
.PHONY : src/Sphere.s

# target to generate assembly for a file
src/Sphere.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Sphere.cpp.s
.PHONY : src/Sphere.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/operations.o: src/operations.cpp.o
.PHONY : src/operations.o

# target to build an object file
src/operations.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/operations.cpp.o
.PHONY : src/operations.cpp.o

src/operations.i: src/operations.cpp.i
.PHONY : src/operations.i

# target to preprocess a source file
src/operations.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/operations.cpp.i
.PHONY : src/operations.cpp.i

src/operations.s: src/operations.cpp.s
.PHONY : src/operations.s

# target to generate assembly for a file
src/operations.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/operations.cpp.s
.PHONY : src/operations.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... ray"
	@echo "... src/AObject.o"
	@echo "... src/AObject.i"
	@echo "... src/AObject.s"
	@echo "... src/Camera.o"
	@echo "... src/Camera.i"
	@echo "... src/Camera.s"
	@echo "... src/Intercection.o"
	@echo "... src/Intercection.i"
	@echo "... src/Intercection.s"
	@echo "... src/Light.o"
	@echo "... src/Light.i"
	@echo "... src/Light.s"
	@echo "... src/Logger.o"
	@echo "... src/Logger.i"
	@echo "... src/Logger.s"
	@echo "... src/Plane.o"
	@echo "... src/Plane.i"
	@echo "... src/Plane.s"
	@echo "... src/Ray.o"
	@echo "... src/Ray.i"
	@echo "... src/Ray.s"
	@echo "... src/Renderer.o"
	@echo "... src/Renderer.i"
	@echo "... src/Renderer.s"
	@echo "... src/Sphere.o"
	@echo "... src/Sphere.i"
	@echo "... src/Sphere.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/operations.o"
	@echo "... src/operations.i"
	@echo "... src/operations.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

