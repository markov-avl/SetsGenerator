cmake_minimum_required(VERSION 3.17)
project(SetsGenerator)

add_subdirectory(googletest)

include_directories(src)
include_directories(googletest/googletest/include)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES src/combinations.cpp src/sets.cpp)

add_executable(main main.cpp ${SOURCE_FILES})
add_executable(test tests.cpp ${SOURCE_FILES})

target_link_libraries(test gtest)