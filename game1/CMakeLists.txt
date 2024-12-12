cmake_minimum_required(VERSION 3.28)
project(game1 C)

set(CMAKE_C_STANDARD 11)

add_executable(game1 main.c
        game.h
        game.c)
