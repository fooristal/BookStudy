cmake_minimum_required(VERSION 2.6)
project(restaurant)

add_library(hamburger hamburger.c)

add_executable(restaurant main.c)
target_link_libraries(restaurant hamburger)