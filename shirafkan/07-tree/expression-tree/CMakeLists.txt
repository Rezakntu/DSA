cmake_minimum_required(VERSION 3.29)
project(expression_tree)

set(CMAKE_CXX_STANDARD 20)

add_executable(expression_tree main.cpp
        ExpressionTree.cpp
        ExpressionTree.h)
