cmake_minimum_required(VERSION 3.29)
project(quick_sort)

set(CMAKE_CXX_STANDARD 20)

add_executable(quick_sort main.cpp
        QuickSorter.cpp
        QuickSorter.h)
