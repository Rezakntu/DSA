cmake_minimum_required(VERSION 3.29)
project(LCA)

set(CMAKE_CXX_STANDARD 20)

add_executable(LCA main.cpp
        BinaryTreeLCA.cpp
        BinaryTreeLCA.h)
