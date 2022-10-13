cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(Labo1_GillesD)

add_executable(labo1 main.c)

include_directories(/usr/include/mariadb /usr/include/mariadb/mysql)

target_link_libraries(labo1 mariadb)
target_link_libraries(labo1 gpiod)