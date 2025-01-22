cmake_minimum_required(VERSION 3.26)

project(
linked_list #Name of Project
VERSION 1.0.0 #Current Version
LANGUAGES C CXX #Languages used
)

set(CMAKE_CXX_STANDARD 17) # C++ Version Being Compiled

file(GLOB_RECURSE SOURCES
        "src/*.h"
        "src/*.cpp"
)
add_executable(linked_list ${SOURCES} )
target_compile_options(linked_list PRIVATE -O0 -Wall -Wextra -ggdb)
