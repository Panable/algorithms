cmake_minimum_required(VERSION 3.26)

project(
vector #Name of Project
VERSION 1.0.0 #Current Version
LANGUAGES C CXX #Languages used
)

set(CMAKE_CXX_STANDARD 17) # C++ Version Being Compiled

file(GLOB_RECURSE SOURCES
        "src/*.h"
        "src/*.cpp"
)
add_executable(vector ${SOURCES} )
target_compile_options(vector PRIVATE -O2 -Wall -Wextra -pedantic)
