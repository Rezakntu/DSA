cmake_minimum_required(VERSION 3.29)
project(complete_tree)

set(CMAKE_CXX_STANDARD 20)

add_executable(complete_tree main.cpp
        BinaryTree.cpp
        BinaryTree.h)
