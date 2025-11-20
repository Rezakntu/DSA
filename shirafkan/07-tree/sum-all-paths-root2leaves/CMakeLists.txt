cmake_minimum_required(VERSION 3.29)
project(sum_all_paths_root2leaves)

set(CMAKE_CXX_STANDARD 20)

add_executable(sum_all_paths_root2leaves main.cpp
        BinaryTree.cpp
        BinaryTree.h)
