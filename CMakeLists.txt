cmake_minimum_required(VERSION 3.27)
project(sae__octo C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(sae__octo
        Jeu.c
        Jeu.h
        main.c
        rail.c
        rail.h
        pioche.h
        pioche.c
)
