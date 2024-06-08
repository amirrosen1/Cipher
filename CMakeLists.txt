cmake_minimum_required(VERSION 3.16)
project(ex1_amir_rosen15 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ex1_amir_rosen15
        cipher.c
        cipher.h
        main.c
        tests.c
        tests.h)
