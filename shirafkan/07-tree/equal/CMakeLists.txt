cmake_minimum_required(VERSION 3.29)
project(equal)

set(CMAKE_CXX_STANDARD 20)

add_executable(equal main.cpp
        Tree.cpp
        Tree.h)
