cmake_minimum_required(VERSION 3.27)
project(sae__octo C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(sae__octo
        chevalet.c
        chevalet.h)
