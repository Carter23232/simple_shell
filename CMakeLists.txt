cmake_minimum_required(VERSION 3.26)
project(New_Folder_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(New_Folder_1
        custom_functions.c
        env.c
        env2.c
        execute.c
        main.c
        main.h
        mystd_f.h
        PATH.c
        readline.c
        std_fun.c
        std_fun2.c)
