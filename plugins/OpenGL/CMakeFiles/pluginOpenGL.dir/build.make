# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL

# Include any dependencies generated for this target.
include CMakeFiles/pluginOpenGL.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pluginOpenGL.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pluginOpenGL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pluginOpenGL.dir/flags.make

CMakeFiles/pluginOpenGL.dir/opgl_main_test.cpp.o: CMakeFiles/pluginOpenGL.dir/flags.make
CMakeFiles/pluginOpenGL.dir/opgl_main_test.cpp.o: opgl_main_test.cpp
CMakeFiles/pluginOpenGL.dir/opgl_main_test.cpp.o: CMakeFiles/pluginOpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pluginOpenGL.dir/opgl_main_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pluginOpenGL.dir/opgl_main_test.cpp.o -MF CMakeFiles/pluginOpenGL.dir/opgl_main_test.cpp.o.d -o CMakeFiles/pluginOpenGL.dir/opgl_main_test.cpp.o -c /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/opgl_main_test.cpp

CMakeFiles/pluginOpenGL.dir/opgl_main_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pluginOpenGL.dir/opgl_main_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/opgl_main_test.cpp > CMakeFiles/pluginOpenGL.dir/opgl_main_test.cpp.i

CMakeFiles/pluginOpenGL.dir/opgl_main_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pluginOpenGL.dir/opgl_main_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/opgl_main_test.cpp -o CMakeFiles/pluginOpenGL.dir/opgl_main_test.cpp.s

CMakeFiles/pluginOpenGL.dir/PluginOpenGL.cpp.o: CMakeFiles/pluginOpenGL.dir/flags.make
CMakeFiles/pluginOpenGL.dir/PluginOpenGL.cpp.o: PluginOpenGL.cpp
CMakeFiles/pluginOpenGL.dir/PluginOpenGL.cpp.o: CMakeFiles/pluginOpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pluginOpenGL.dir/PluginOpenGL.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pluginOpenGL.dir/PluginOpenGL.cpp.o -MF CMakeFiles/pluginOpenGL.dir/PluginOpenGL.cpp.o.d -o CMakeFiles/pluginOpenGL.dir/PluginOpenGL.cpp.o -c /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/PluginOpenGL.cpp

CMakeFiles/pluginOpenGL.dir/PluginOpenGL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pluginOpenGL.dir/PluginOpenGL.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/PluginOpenGL.cpp > CMakeFiles/pluginOpenGL.dir/PluginOpenGL.cpp.i

CMakeFiles/pluginOpenGL.dir/PluginOpenGL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pluginOpenGL.dir/PluginOpenGL.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/PluginOpenGL.cpp -o CMakeFiles/pluginOpenGL.dir/PluginOpenGL.cpp.s

CMakeFiles/pluginOpenGL.dir/PluginShader.gl.cpp.o: CMakeFiles/pluginOpenGL.dir/flags.make
CMakeFiles/pluginOpenGL.dir/PluginShader.gl.cpp.o: PluginShader.gl.cpp
CMakeFiles/pluginOpenGL.dir/PluginShader.gl.cpp.o: CMakeFiles/pluginOpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pluginOpenGL.dir/PluginShader.gl.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pluginOpenGL.dir/PluginShader.gl.cpp.o -MF CMakeFiles/pluginOpenGL.dir/PluginShader.gl.cpp.o.d -o CMakeFiles/pluginOpenGL.dir/PluginShader.gl.cpp.o -c /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/PluginShader.gl.cpp

CMakeFiles/pluginOpenGL.dir/PluginShader.gl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pluginOpenGL.dir/PluginShader.gl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/PluginShader.gl.cpp > CMakeFiles/pluginOpenGL.dir/PluginShader.gl.cpp.i

CMakeFiles/pluginOpenGL.dir/PluginShader.gl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pluginOpenGL.dir/PluginShader.gl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/PluginShader.gl.cpp -o CMakeFiles/pluginOpenGL.dir/PluginShader.gl.cpp.s

CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp.o: CMakeFiles/pluginOpenGL.dir/flags.make
CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp.o: /home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp
CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp.o: CMakeFiles/pluginOpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp.o -MF CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp.o.d -o CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp.o -c /home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp

CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp > CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp.i

CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp -o CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp.s

CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp.o: CMakeFiles/pluginOpenGL.dir/flags.make
CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp.o: /home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp
CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp.o: CMakeFiles/pluginOpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp.o -MF CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp.o.d -o CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp.o -c /home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp

CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp > CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp.i

CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp -o CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp.s

CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp.o: CMakeFiles/pluginOpenGL.dir/flags.make
CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp.o: /home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp
CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp.o: CMakeFiles/pluginOpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp.o -MF CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp.o.d -o CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp.o -c /home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp

CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp > CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp.i

CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp -o CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp.s

CMakeFiles/pluginOpenGL.dir/glad/src/gl.c.o: CMakeFiles/pluginOpenGL.dir/flags.make
CMakeFiles/pluginOpenGL.dir/glad/src/gl.c.o: glad/src/gl.c
CMakeFiles/pluginOpenGL.dir/glad/src/gl.c.o: CMakeFiles/pluginOpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/pluginOpenGL.dir/glad/src/gl.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pluginOpenGL.dir/glad/src/gl.c.o -MF CMakeFiles/pluginOpenGL.dir/glad/src/gl.c.o.d -o CMakeFiles/pluginOpenGL.dir/glad/src/gl.c.o -c /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/glad/src/gl.c

CMakeFiles/pluginOpenGL.dir/glad/src/gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pluginOpenGL.dir/glad/src/gl.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/glad/src/gl.c > CMakeFiles/pluginOpenGL.dir/glad/src/gl.c.i

CMakeFiles/pluginOpenGL.dir/glad/src/gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pluginOpenGL.dir/glad/src/gl.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/glad/src/gl.c -o CMakeFiles/pluginOpenGL.dir/glad/src/gl.c.s

# Object files for target pluginOpenGL
pluginOpenGL_OBJECTS = \
"CMakeFiles/pluginOpenGL.dir/opgl_main_test.cpp.o" \
"CMakeFiles/pluginOpenGL.dir/PluginOpenGL.cpp.o" \
"CMakeFiles/pluginOpenGL.dir/PluginShader.gl.cpp.o" \
"CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp.o" \
"CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp.o" \
"CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp.o" \
"CMakeFiles/pluginOpenGL.dir/glad/src/gl.c.o"

# External object files for target pluginOpenGL
pluginOpenGL_EXTERNAL_OBJECTS =

pluginOpenGL: CMakeFiles/pluginOpenGL.dir/opgl_main_test.cpp.o
pluginOpenGL: CMakeFiles/pluginOpenGL.dir/PluginOpenGL.cpp.o
pluginOpenGL: CMakeFiles/pluginOpenGL.dir/PluginShader.gl.cpp.o
pluginOpenGL: CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/PluginManager.cpp.o
pluginOpenGL: CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/Plugin.cpp.o
pluginOpenGL: CMakeFiles/pluginOpenGL.dir/home/Amour/Documents/Epitech/Tech2/ray/src/DLLoader.cpp.o
pluginOpenGL: CMakeFiles/pluginOpenGL.dir/glad/src/gl.c.o
pluginOpenGL: CMakeFiles/pluginOpenGL.dir/build.make
pluginOpenGL: glfw/src/libglfw3.a
pluginOpenGL: /usr/lib64/librt.a
pluginOpenGL: /usr/lib64/libm.so
pluginOpenGL: /usr/lib64/libGLX.so
pluginOpenGL: /usr/lib64/libOpenGL.so
pluginOpenGL: CMakeFiles/pluginOpenGL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable pluginOpenGL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pluginOpenGL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pluginOpenGL.dir/build: pluginOpenGL
.PHONY : CMakeFiles/pluginOpenGL.dir/build

CMakeFiles/pluginOpenGL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pluginOpenGL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pluginOpenGL.dir/clean

CMakeFiles/pluginOpenGL.dir/depend:
	cd /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL /home/Amour/Documents/Epitech/Tech2/ray/plugins/OpenGL/CMakeFiles/pluginOpenGL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pluginOpenGL.dir/depend

