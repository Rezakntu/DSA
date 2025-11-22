cmake_minimum_required(VERSION 3.29)
project(AVL_insert)

set(CMAKE_CXX_STANDARD 20)

add_executable(AVL_insert main.cpp
        AVLTree.cpp
        AVLTree.h)
