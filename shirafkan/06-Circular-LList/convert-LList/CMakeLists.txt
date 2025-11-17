cmake_minimum_required(VERSION 3.29)
project(convert_LList)

set(CMAKE_CXX_STANDARD 20)

add_executable(convert_LList main.cpp
        convert_sll_to_cll.cpp
        convert_sll_to_cll.h)
