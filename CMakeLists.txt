cmake_minimum_required(VERSION 3.10)
project(MatrixTemplate)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES Matrix.h main.cpp MatrixDimensionException.h MatrixFactory.h)
add_executable(MatrixTemplate main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(MatrixTemplate core)