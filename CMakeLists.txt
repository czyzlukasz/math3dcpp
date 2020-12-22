cmake_minimum_required(VERSION 3.12)
project(math3dcpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(Src)

add_library(math3dcpp Src/VectorImpl.cpp Src/Matrix.cpp Src/Quaternion.cpp Src/Vector.cpp)

# Uts
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB TEST_FILES Uts/*Test.cpp)

add_executable(Tests ${TEST_FILES} Uts/MatrixTest.cpp Uts/QuaternionTest.cpp)
target_link_libraries(Tests gtest gtest_main pthread math3dcpp)