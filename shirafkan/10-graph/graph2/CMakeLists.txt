cmake_minimum_required(VERSION 3.29)
project(graph2)

set(CMAKE_CXX_STANDARD 20)

add_executable(graph2 main.cpp
        graph.cpp
        graph.h)
