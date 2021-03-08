cmake_minimum_required(VERSION 3.5)

project(readData)

# add OpenCV package to the project
find_package(OpenCV REQUIRED)
find_package(OpenGL)

if(OPENGL_FOUND)
	include_directories(${OpenCV_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})
else()
	include_directories(${OpenCV_INCLUDE_DIRS})
endif()

# OOIMPILE
add_executable(${PROJECT_NAME} main.cpp)

# LINK
set(OpenCV_LIBRARIES ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})




