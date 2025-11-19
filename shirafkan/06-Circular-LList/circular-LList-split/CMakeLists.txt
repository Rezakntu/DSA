cmake_minimum_required(VERSION 3.29)
project(circular_LList_split)

set(CMAKE_CXX_STANDARD 20)

add_executable(circular_LList_split main.cpp
        CircularList.cpp
        CircularList.h)
