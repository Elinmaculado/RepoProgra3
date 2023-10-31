cmake_minimum_required(VERSION 3.26)
project(DLList)

set(CMAKE_CXX_STANDARD 17)

add_executable(DLList main.cpp
        Stack.h
        Queue.h
        SLList.h
        DLList.h
        Stack.h)
