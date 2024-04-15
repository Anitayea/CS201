cmake_minimum_required(VERSION 3.23)
project(project2 C)

set(CMAKE_C_STANDARD 99)

add_executable(project2 main.c dynamicarray.c dynamicarray.h)
