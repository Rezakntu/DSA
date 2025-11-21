cmake_minimum_required(VERSION 3.29)
project(levelOrder)

set(CMAKE_CXX_STANDARD 20)

add_executable(levelOrder main.cpp
        BinaryTree.cpp
        BinaryTree.h)
