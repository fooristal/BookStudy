cmake_minimum_required(VERSION 3.5)

project(GaussianBlur)

# add opencv package to the project
#set(OpenCV_DIR C:/OpenCV/opencv-3.4.6)
find_package(OpenCV REQUIRED)
find_package(OpenGL)

if(OPENGL_FOUND)
	include_directories(${OpenCV_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})
else()
	include_directories(${OpenCV_INCLUDE_DIRS})
endif()

# OOIMPILE
add_executable(GaussianBlur main.cpp)

# LINK
#set(OpenCV_LIBRARIES ${OpenCV_LIBS})
target_link_libraries(GaussianBlur ${OpenCV_LIBS})




