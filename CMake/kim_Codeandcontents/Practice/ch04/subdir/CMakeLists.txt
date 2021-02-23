cmake_minimum_required(VERSION 2.8)
project(Restaurant)

add_subdirectory(food)
include_directories("${PROJECT_SOURCE_DIR}/food")
add_subdirectory(drink)
include_directories("${PROJECT_SOURCE_DIR}/drink")

add_executable(restaurant main.c)
target_link_libraries(restaurant food)
target_link_libraries(restaurant drink)