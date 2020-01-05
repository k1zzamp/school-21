cmake_minimum_required(VERSION 3.15)
project(lem_in C)

set(CMAKE_C_STANDARD 99)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(lem_in main.c lem_in.h parser.c libft_functions.c utils.c ft_strsplit.c errors.c set_rooms.c libft_functions_2.c set_links.c free.c pathfinding.c libft_functions_3.c send_ants.c)