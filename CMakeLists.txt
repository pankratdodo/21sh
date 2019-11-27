cmake_minimum_required(VERSION 3.15)
project(21 C)

set(CMAKE_C_STANDARD 11)

include_directories(Includes)

add_executable(21
        Includes/list.h
        Includes/sh.h
        Sources/cd.c
        Sources/commands.c
        Sources/env.c
        Sources/exit.c
        Sources/ft.c
        Sources/ft_2.c
        Sources/ft_split_whitespaces.c
        Sources/ft_strsplit.c
        Sources/list.c
        Sources/sh.c
        Sources/readline.c
        Sources/shell.c
        Sources/unstandart.c
        Sources/unstandart_2.c Sources/redirection.c Sources/ft_3.c)
