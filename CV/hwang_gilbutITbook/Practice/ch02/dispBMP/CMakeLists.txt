cmake_minimum_required(VERSION 3.5)

project(dispBMP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dispBMP main.cpp)

# add opencv package to the project
set(OpenCV_DIR C:/OpenCV/opencv-3.4.6)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(OpenCV_LIBRARIES ${OpenCV_LIBS})
target_link_libraries(dispBMP ${OpenCV_LIBS})

message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

#set(IMG_DIR F:/98_BookStudy/CV/hwang_gilbutITbook/Data/images)
#set (IMAGES ${IMG_DIR}/lena.jpg)
#FILE(COPY ${IMAGES} DESTINATION .)
