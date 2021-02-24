cmake_minimum_required(VERSION 2.8)
project(Restaurant)

add_definitions(-DFOOD)

add_subdirectory(food)
include_directories("${PROJECT_SOURCE_DIR}/food")
add_subdirectory(drink)
include_directories("${PROJECT_SOURCE_DIR}/drink")

set(WANT_DESERT 2)
configure_file("${PROJECT_SOURCE_DIR}/desert.h.in"
"${PROJECT_BINARY_DIR}/desert.h")
include_directories("${PROJECT_BINARY_DIR}")

add_executable(restaurant main.c)
target_link_libraries(restaurant food)
target_link_libraries(restaurant drink)