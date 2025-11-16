cmake_minimum_required(VERSION 3.29)
project(linked_list_class)

set(CMAKE_CXX_STANDARD 20)

add_executable(linked_list_class main.cpp
        LinkedList.cpp
        LinkedList.h)
