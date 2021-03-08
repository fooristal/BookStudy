cmake_minimum_required(VERSION 3.5)

project(helloCV LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(helloCV main.cpp)

# add opencv package to the project
set(OpenCV_DIR C:/OpenCV/opencv-3.4.6)
find_package(OpenCV REQUIRED)
set(OpenCV_LIBRARIES ${OpenCV_LIBS})
target_link_libraries(helloCV ${OpenCV_LIBS})

message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

