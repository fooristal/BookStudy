cmake_minimum_required(VERSION 2.8)
project(Restaurant)

set(my_lib "${PROJECT_SOURCE_DIR}/lib")
set(my_include "${PROJECT_SOURCE_DIR}/include")

add_library(food SHARED hamburger.c steak.c)

install(TARGETS food DESTINATION ${my_lib})
install(FILES hamburger.h steak.h DESTINATION ${my_include})