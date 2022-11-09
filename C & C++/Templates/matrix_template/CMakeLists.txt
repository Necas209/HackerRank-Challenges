cmake_minimum_required(VERSION 3.22)
project(Matrix_Template)

set(CMAKE_CXX_STANDARD 20)

add_executable(op_overloading "op_overloading.cpp" "matrix.h" "matrix.cpp")