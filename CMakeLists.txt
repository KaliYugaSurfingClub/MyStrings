cmake_minimum_required(VERSION 3.27)
project(my_string)

set(CMAKE_CXX_STANDARD 17)

add_executable(my_string src/main.cpp
        src/My_string.cpp
        includes/My_string.h)
