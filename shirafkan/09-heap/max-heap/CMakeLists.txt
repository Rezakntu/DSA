cmake_minimum_required(VERSION 3.29)
project(max_heap)

set(CMAKE_CXX_STANDARD 20)

add_executable(max_heap main.cpp
        MaxHeap.cpp
        MaxHeap.h)
