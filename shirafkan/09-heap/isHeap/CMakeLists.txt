cmake_minimum_required(VERSION 3.29)
project(isHeap)

set(CMAKE_CXX_STANDARD 20)

add_executable(isHeap main.cpp
        HeapChecker.cpp
        HeapChecker.h)
