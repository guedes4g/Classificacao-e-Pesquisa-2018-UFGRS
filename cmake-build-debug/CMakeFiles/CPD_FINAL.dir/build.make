# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/guedes/Downloads/clion-2018.1.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/guedes/Downloads/clion-2018.1.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/guedes/CLionProjects/CPD_FINAL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guedes/CLionProjects/CPD_FINAL/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CPD_FINAL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CPD_FINAL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPD_FINAL.dir/flags.make

CMakeFiles/CPD_FINAL.dir/main.cpp.o: CMakeFiles/CPD_FINAL.dir/flags.make
CMakeFiles/CPD_FINAL.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guedes/CLionProjects/CPD_FINAL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPD_FINAL.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPD_FINAL.dir/main.cpp.o -c /home/guedes/CLionProjects/CPD_FINAL/main.cpp

CMakeFiles/CPD_FINAL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPD_FINAL.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guedes/CLionProjects/CPD_FINAL/main.cpp > CMakeFiles/CPD_FINAL.dir/main.cpp.i

CMakeFiles/CPD_FINAL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPD_FINAL.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guedes/CLionProjects/CPD_FINAL/main.cpp -o CMakeFiles/CPD_FINAL.dir/main.cpp.s

CMakeFiles/CPD_FINAL.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/CPD_FINAL.dir/main.cpp.o.requires

CMakeFiles/CPD_FINAL.dir/main.cpp.o.provides: CMakeFiles/CPD_FINAL.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/CPD_FINAL.dir/build.make CMakeFiles/CPD_FINAL.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/CPD_FINAL.dir/main.cpp.o.provides

CMakeFiles/CPD_FINAL.dir/main.cpp.o.provides.build: CMakeFiles/CPD_FINAL.dir/main.cpp.o


CMakeFiles/CPD_FINAL.dir/Trie.cpp.o: CMakeFiles/CPD_FINAL.dir/flags.make
CMakeFiles/CPD_FINAL.dir/Trie.cpp.o: ../Trie.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guedes/CLionProjects/CPD_FINAL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CPD_FINAL.dir/Trie.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPD_FINAL.dir/Trie.cpp.o -c /home/guedes/CLionProjects/CPD_FINAL/Trie.cpp

CMakeFiles/CPD_FINAL.dir/Trie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPD_FINAL.dir/Trie.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guedes/CLionProjects/CPD_FINAL/Trie.cpp > CMakeFiles/CPD_FINAL.dir/Trie.cpp.i

CMakeFiles/CPD_FINAL.dir/Trie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPD_FINAL.dir/Trie.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guedes/CLionProjects/CPD_FINAL/Trie.cpp -o CMakeFiles/CPD_FINAL.dir/Trie.cpp.s

CMakeFiles/CPD_FINAL.dir/Trie.cpp.o.requires:

.PHONY : CMakeFiles/CPD_FINAL.dir/Trie.cpp.o.requires

CMakeFiles/CPD_FINAL.dir/Trie.cpp.o.provides: CMakeFiles/CPD_FINAL.dir/Trie.cpp.o.requires
	$(MAKE) -f CMakeFiles/CPD_FINAL.dir/build.make CMakeFiles/CPD_FINAL.dir/Trie.cpp.o.provides.build
.PHONY : CMakeFiles/CPD_FINAL.dir/Trie.cpp.o.provides

CMakeFiles/CPD_FINAL.dir/Trie.cpp.o.provides.build: CMakeFiles/CPD_FINAL.dir/Trie.cpp.o


CMakeFiles/CPD_FINAL.dir/HashMap.cpp.o: CMakeFiles/CPD_FINAL.dir/flags.make
CMakeFiles/CPD_FINAL.dir/HashMap.cpp.o: ../HashMap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guedes/CLionProjects/CPD_FINAL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CPD_FINAL.dir/HashMap.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPD_FINAL.dir/HashMap.cpp.o -c /home/guedes/CLionProjects/CPD_FINAL/HashMap.cpp

CMakeFiles/CPD_FINAL.dir/HashMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPD_FINAL.dir/HashMap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guedes/CLionProjects/CPD_FINAL/HashMap.cpp > CMakeFiles/CPD_FINAL.dir/HashMap.cpp.i

CMakeFiles/CPD_FINAL.dir/HashMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPD_FINAL.dir/HashMap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guedes/CLionProjects/CPD_FINAL/HashMap.cpp -o CMakeFiles/CPD_FINAL.dir/HashMap.cpp.s

CMakeFiles/CPD_FINAL.dir/HashMap.cpp.o.requires:

.PHONY : CMakeFiles/CPD_FINAL.dir/HashMap.cpp.o.requires

CMakeFiles/CPD_FINAL.dir/HashMap.cpp.o.provides: CMakeFiles/CPD_FINAL.dir/HashMap.cpp.o.requires
	$(MAKE) -f CMakeFiles/CPD_FINAL.dir/build.make CMakeFiles/CPD_FINAL.dir/HashMap.cpp.o.provides.build
.PHONY : CMakeFiles/CPD_FINAL.dir/HashMap.cpp.o.provides

CMakeFiles/CPD_FINAL.dir/HashMap.cpp.o.provides.build: CMakeFiles/CPD_FINAL.dir/HashMap.cpp.o


CMakeFiles/CPD_FINAL.dir/BTree.cpp.o: CMakeFiles/CPD_FINAL.dir/flags.make
CMakeFiles/CPD_FINAL.dir/BTree.cpp.o: ../BTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guedes/CLionProjects/CPD_FINAL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CPD_FINAL.dir/BTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPD_FINAL.dir/BTree.cpp.o -c /home/guedes/CLionProjects/CPD_FINAL/BTree.cpp

CMakeFiles/CPD_FINAL.dir/BTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPD_FINAL.dir/BTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guedes/CLionProjects/CPD_FINAL/BTree.cpp > CMakeFiles/CPD_FINAL.dir/BTree.cpp.i

CMakeFiles/CPD_FINAL.dir/BTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPD_FINAL.dir/BTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guedes/CLionProjects/CPD_FINAL/BTree.cpp -o CMakeFiles/CPD_FINAL.dir/BTree.cpp.s

CMakeFiles/CPD_FINAL.dir/BTree.cpp.o.requires:

.PHONY : CMakeFiles/CPD_FINAL.dir/BTree.cpp.o.requires

CMakeFiles/CPD_FINAL.dir/BTree.cpp.o.provides: CMakeFiles/CPD_FINAL.dir/BTree.cpp.o.requires
	$(MAKE) -f CMakeFiles/CPD_FINAL.dir/build.make CMakeFiles/CPD_FINAL.dir/BTree.cpp.o.provides.build
.PHONY : CMakeFiles/CPD_FINAL.dir/BTree.cpp.o.provides

CMakeFiles/CPD_FINAL.dir/BTree.cpp.o.provides.build: CMakeFiles/CPD_FINAL.dir/BTree.cpp.o


CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.o: CMakeFiles/CPD_FINAL.dir/flags.make
CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.o: ../WordAvg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guedes/CLionProjects/CPD_FINAL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.o -c /home/guedes/CLionProjects/CPD_FINAL/WordAvg.cpp

CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guedes/CLionProjects/CPD_FINAL/WordAvg.cpp > CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.i

CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guedes/CLionProjects/CPD_FINAL/WordAvg.cpp -o CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.s

CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.o.requires:

.PHONY : CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.o.requires

CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.o.provides: CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.o.requires
	$(MAKE) -f CMakeFiles/CPD_FINAL.dir/build.make CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.o.provides.build
.PHONY : CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.o.provides

CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.o.provides.build: CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.o


CMakeFiles/CPD_FINAL.dir/Helper.cpp.o: CMakeFiles/CPD_FINAL.dir/flags.make
CMakeFiles/CPD_FINAL.dir/Helper.cpp.o: ../Helper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guedes/CLionProjects/CPD_FINAL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CPD_FINAL.dir/Helper.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPD_FINAL.dir/Helper.cpp.o -c /home/guedes/CLionProjects/CPD_FINAL/Helper.cpp

CMakeFiles/CPD_FINAL.dir/Helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPD_FINAL.dir/Helper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guedes/CLionProjects/CPD_FINAL/Helper.cpp > CMakeFiles/CPD_FINAL.dir/Helper.cpp.i

CMakeFiles/CPD_FINAL.dir/Helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPD_FINAL.dir/Helper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guedes/CLionProjects/CPD_FINAL/Helper.cpp -o CMakeFiles/CPD_FINAL.dir/Helper.cpp.s

CMakeFiles/CPD_FINAL.dir/Helper.cpp.o.requires:

.PHONY : CMakeFiles/CPD_FINAL.dir/Helper.cpp.o.requires

CMakeFiles/CPD_FINAL.dir/Helper.cpp.o.provides: CMakeFiles/CPD_FINAL.dir/Helper.cpp.o.requires
	$(MAKE) -f CMakeFiles/CPD_FINAL.dir/build.make CMakeFiles/CPD_FINAL.dir/Helper.cpp.o.provides.build
.PHONY : CMakeFiles/CPD_FINAL.dir/Helper.cpp.o.provides

CMakeFiles/CPD_FINAL.dir/Helper.cpp.o.provides.build: CMakeFiles/CPD_FINAL.dir/Helper.cpp.o


CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.o: CMakeFiles/CPD_FINAL.dir/flags.make
CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.o: ../WordInfo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guedes/CLionProjects/CPD_FINAL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.o -c /home/guedes/CLionProjects/CPD_FINAL/WordInfo.cpp

CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/guedes/CLionProjects/CPD_FINAL/WordInfo.cpp > CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.i

CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/guedes/CLionProjects/CPD_FINAL/WordInfo.cpp -o CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.s

CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.o.requires:

.PHONY : CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.o.requires

CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.o.provides: CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.o.requires
	$(MAKE) -f CMakeFiles/CPD_FINAL.dir/build.make CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.o.provides.build
.PHONY : CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.o.provides

CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.o.provides.build: CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.o


# Object files for target CPD_FINAL
CPD_FINAL_OBJECTS = \
"CMakeFiles/CPD_FINAL.dir/main.cpp.o" \
"CMakeFiles/CPD_FINAL.dir/Trie.cpp.o" \
"CMakeFiles/CPD_FINAL.dir/HashMap.cpp.o" \
"CMakeFiles/CPD_FINAL.dir/BTree.cpp.o" \
"CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.o" \
"CMakeFiles/CPD_FINAL.dir/Helper.cpp.o" \
"CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.o"

# External object files for target CPD_FINAL
CPD_FINAL_EXTERNAL_OBJECTS =

CPD_FINAL: CMakeFiles/CPD_FINAL.dir/main.cpp.o
CPD_FINAL: CMakeFiles/CPD_FINAL.dir/Trie.cpp.o
CPD_FINAL: CMakeFiles/CPD_FINAL.dir/HashMap.cpp.o
CPD_FINAL: CMakeFiles/CPD_FINAL.dir/BTree.cpp.o
CPD_FINAL: CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.o
CPD_FINAL: CMakeFiles/CPD_FINAL.dir/Helper.cpp.o
CPD_FINAL: CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.o
CPD_FINAL: CMakeFiles/CPD_FINAL.dir/build.make
CPD_FINAL: CMakeFiles/CPD_FINAL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guedes/CLionProjects/CPD_FINAL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable CPD_FINAL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPD_FINAL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPD_FINAL.dir/build: CPD_FINAL

.PHONY : CMakeFiles/CPD_FINAL.dir/build

CMakeFiles/CPD_FINAL.dir/requires: CMakeFiles/CPD_FINAL.dir/main.cpp.o.requires
CMakeFiles/CPD_FINAL.dir/requires: CMakeFiles/CPD_FINAL.dir/Trie.cpp.o.requires
CMakeFiles/CPD_FINAL.dir/requires: CMakeFiles/CPD_FINAL.dir/HashMap.cpp.o.requires
CMakeFiles/CPD_FINAL.dir/requires: CMakeFiles/CPD_FINAL.dir/BTree.cpp.o.requires
CMakeFiles/CPD_FINAL.dir/requires: CMakeFiles/CPD_FINAL.dir/WordAvg.cpp.o.requires
CMakeFiles/CPD_FINAL.dir/requires: CMakeFiles/CPD_FINAL.dir/Helper.cpp.o.requires
CMakeFiles/CPD_FINAL.dir/requires: CMakeFiles/CPD_FINAL.dir/WordInfo.cpp.o.requires

.PHONY : CMakeFiles/CPD_FINAL.dir/requires

CMakeFiles/CPD_FINAL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPD_FINAL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPD_FINAL.dir/clean

CMakeFiles/CPD_FINAL.dir/depend:
	cd /home/guedes/CLionProjects/CPD_FINAL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guedes/CLionProjects/CPD_FINAL /home/guedes/CLionProjects/CPD_FINAL /home/guedes/CLionProjects/CPD_FINAL/cmake-build-debug /home/guedes/CLionProjects/CPD_FINAL/cmake-build-debug /home/guedes/CLionProjects/CPD_FINAL/cmake-build-debug/CMakeFiles/CPD_FINAL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPD_FINAL.dir/depend

