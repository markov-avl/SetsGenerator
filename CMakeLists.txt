cmake_minimum_required(VERSION 3.17)
project(SetsGenerator)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(SetsGenerator main.cpp src/combinations.cpp src/combinations.h src/sets.cpp src/sets.h)