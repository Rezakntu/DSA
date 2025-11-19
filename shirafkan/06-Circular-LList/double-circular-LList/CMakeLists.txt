cmake_minimum_required(VERSION 3.29)
project(double_circular_LList)

set(CMAKE_CXX_STANDARD 20)

add_executable(double_circular_LList main.cpp
        CircularDoublyList.cpp
        CircularDoublyList.h)
