cmake_minimum_required(VERSION 3.28.3)
project(neurogami)

set(CMAKE_CXX_STANDARD 26)

# Recursively grab all .cpp and .h files inside src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
    src/*.h
)

add_executable(neurogami ${SOURCES})