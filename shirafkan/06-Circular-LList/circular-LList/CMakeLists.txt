cmake_minimum_required(VERSION 3.29)
project(circular_LList)

set(CMAKE_CXX_STANDARD 20)

add_executable(circular_LList main.cpp
        CircularLinkedList.cpp
        CircularLinkedList.h)
