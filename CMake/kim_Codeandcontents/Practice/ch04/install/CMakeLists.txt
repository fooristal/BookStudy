cmake_minimum_required(VERSION 2.8)
project(Restaurant)

set(my_bin "${PROJECT_SOURCE_DIR}/bin")

add_executable(restaurant main.c)
target_link_libraries(restaurant food)
install(TARGETS restaurant DESTINATION ${my_bin})
add_custom_target(cleanup
	COMMAND rm -rf "${PROJECT_SOURCE_DIR}/bin/restaurant.exe"
	COMMAND rm -rf "${PROJECT_SOURCE_DIR}/food/include/hamburger.h"
	COMMAND rm -rf "${PROJECT_SOURCE_DIR}/food/include/steak.h"
	COMMAND rm -rf "${PROJECT_SOURCE_DIR}/food/lib/food.lib")