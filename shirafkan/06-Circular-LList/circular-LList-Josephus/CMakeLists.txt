cmake_minimum_required(VERSION 3.29)
project(circular_LList_Josephus)

set(CMAKE_CXX_STANDARD 20)

add_executable(circular_LList_Josephus main.cpp
        JosephusList.cpp
        JosephusList.h)
