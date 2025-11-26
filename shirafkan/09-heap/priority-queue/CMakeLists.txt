cmake_minimum_required(VERSION 3.29)
project(priority_queue)

set(CMAKE_CXX_STANDARD 20)

add_executable(priority_queue main.cpp
        PriorityQueue.cpp
        PriorityQueue.h)
