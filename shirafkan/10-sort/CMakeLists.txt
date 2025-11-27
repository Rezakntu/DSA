cmake_minimum_required(VERSION 3.29)
project(10_sort)

set(CMAKE_CXX_STANDARD 20)

add_executable(10_sort main.cpp
        SelectionSort.cpp
        SelectionSort.h)
