# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_SOURCE_DIR = /home/vpy/delivery/2year/OOP/raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vpy/delivery/2year/OOP/raytracer

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
	$(CMAKE_COMMAND) -E cmake_progress_start /home/vpy/delivery/2year/OOP/raytracer/CMakeFiles /home/vpy/delivery/2year/OOP/raytracer//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/vpy/delivery/2year/OOP/raytracer/CMakeFiles 0
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

#=============================================================================
# Target rules for targets named Wrapper.v

# Build rule for target.
Wrapper.v: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Wrapper.v
.PHONY : Wrapper.v

# fast build rule for target.
Wrapper.v/fast:
	$(MAKE) $(MAKESILENT) -f src/plugins/Vanille/CMakeFiles/Wrapper.v.dir/build.make src/plugins/Vanille/CMakeFiles/Wrapper.v.dir/build
.PHONY : Wrapper.v/fast

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

src/ConfigLoader.o: src/ConfigLoader.cpp.o
.PHONY : src/ConfigLoader.o

# target to build an object file
src/ConfigLoader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/ConfigLoader.cpp.o
.PHONY : src/ConfigLoader.cpp.o

src/ConfigLoader.i: src/ConfigLoader.cpp.i
.PHONY : src/ConfigLoader.i

# target to preprocess a source file
src/ConfigLoader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/ConfigLoader.cpp.i
.PHONY : src/ConfigLoader.cpp.i

src/ConfigLoader.s: src/ConfigLoader.cpp.s
.PHONY : src/ConfigLoader.s

# target to generate assembly for a file
src/ConfigLoader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/ConfigLoader.cpp.s
.PHONY : src/ConfigLoader.cpp.s

src/DLLoader.o: src/DLLoader.cpp.o
.PHONY : src/DLLoader.o

# target to build an object file
src/DLLoader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/DLLoader.cpp.o
.PHONY : src/DLLoader.cpp.o

src/DLLoader.i: src/DLLoader.cpp.i
.PHONY : src/DLLoader.i

# target to preprocess a source file
src/DLLoader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/DLLoader.cpp.i
.PHONY : src/DLLoader.cpp.i

src/DLLoader.s: src/DLLoader.cpp.s
.PHONY : src/DLLoader.s

# target to generate assembly for a file
src/DLLoader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/DLLoader.cpp.s
.PHONY : src/DLLoader.cpp.s

src/Entity.o: src/Entity.cpp.o
.PHONY : src/Entity.o

# target to build an object file
src/Entity.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Entity.cpp.o
.PHONY : src/Entity.cpp.o

src/Entity.i: src/Entity.cpp.i
.PHONY : src/Entity.i

# target to preprocess a source file
src/Entity.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Entity.cpp.i
.PHONY : src/Entity.cpp.i

src/Entity.s: src/Entity.cpp.s
.PHONY : src/Entity.s

# target to generate assembly for a file
src/Entity.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/Entity.cpp.s
.PHONY : src/Entity.cpp.s

src/PluginManagement/Plugin.o: src/PluginManagement/Plugin.cpp.o
.PHONY : src/PluginManagement/Plugin.o

# target to build an object file
src/PluginManagement/Plugin.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/PluginManagement/Plugin.cpp.o
.PHONY : src/PluginManagement/Plugin.cpp.o

src/PluginManagement/Plugin.i: src/PluginManagement/Plugin.cpp.i
.PHONY : src/PluginManagement/Plugin.i

# target to preprocess a source file
src/PluginManagement/Plugin.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/PluginManagement/Plugin.cpp.i
.PHONY : src/PluginManagement/Plugin.cpp.i

src/PluginManagement/Plugin.s: src/PluginManagement/Plugin.cpp.s
.PHONY : src/PluginManagement/Plugin.s

# target to generate assembly for a file
src/PluginManagement/Plugin.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/PluginManagement/Plugin.cpp.s
.PHONY : src/PluginManagement/Plugin.cpp.s

src/PluginManagement/PluginManager.o: src/PluginManagement/PluginManager.cpp.o
.PHONY : src/PluginManagement/PluginManager.o

# target to build an object file
src/PluginManagement/PluginManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/PluginManagement/PluginManager.cpp.o
.PHONY : src/PluginManagement/PluginManager.cpp.o

src/PluginManagement/PluginManager.i: src/PluginManagement/PluginManager.cpp.i
.PHONY : src/PluginManagement/PluginManager.i

# target to preprocess a source file
src/PluginManagement/PluginManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/PluginManagement/PluginManager.cpp.i
.PHONY : src/PluginManagement/PluginManager.cpp.i

src/PluginManagement/PluginManager.s: src/PluginManagement/PluginManager.cpp.s
.PHONY : src/PluginManagement/PluginManager.s

# target to generate assembly for a file
src/PluginManagement/PluginManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/PluginManagement/PluginManager.cpp.s
.PHONY : src/PluginManagement/PluginManager.cpp.s

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

src/geometry.o: src/geometry.cpp.o
.PHONY : src/geometry.o

# target to build an object file
src/geometry.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/geometry.cpp.o
.PHONY : src/geometry.cpp.o

src/geometry.i: src/geometry.cpp.i
.PHONY : src/geometry.i

# target to preprocess a source file
src/geometry.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/geometry.cpp.i
.PHONY : src/geometry.cpp.i

src/geometry.s: src/geometry.cpp.s
.PHONY : src/geometry.s

# target to generate assembly for a file
src/geometry.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/geometry.cpp.s
.PHONY : src/geometry.cpp.s

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
	@echo "... Wrapper.v"
	@echo "... ray"
	@echo "... src/Camera.o"
	@echo "... src/Camera.i"
	@echo "... src/Camera.s"
	@echo "... src/ConfigLoader.o"
	@echo "... src/ConfigLoader.i"
	@echo "... src/ConfigLoader.s"
	@echo "... src/DLLoader.o"
	@echo "... src/DLLoader.i"
	@echo "... src/DLLoader.s"
	@echo "... src/Entity.o"
	@echo "... src/Entity.i"
	@echo "... src/Entity.s"
	@echo "... src/PluginManagement/Plugin.o"
	@echo "... src/PluginManagement/Plugin.i"
	@echo "... src/PluginManagement/Plugin.s"
	@echo "... src/PluginManagement/PluginManager.o"
	@echo "... src/PluginManagement/PluginManager.i"
	@echo "... src/PluginManagement/PluginManager.s"
	@echo "... src/Ray.o"
	@echo "... src/Ray.i"
	@echo "... src/Ray.s"
	@echo "... src/Renderer.o"
	@echo "... src/Renderer.i"
	@echo "... src/Renderer.s"
	@echo "... src/geometry.o"
	@echo "... src/geometry.i"
	@echo "... src/geometry.s"
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

