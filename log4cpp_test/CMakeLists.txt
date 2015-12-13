cmake_minimum_required(VERSION 3.3)
project(log4cpp_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread ")
include_directories("/mnt/home/feng/workspace/lib/log4cpp/include")
set(SOURCE_FILES main.cpp log4cpp_config.cpp)
add_executable(log4cpp_test ${SOURCE_FILES})
target_link_libraries(log4cpp_test pthread log4cpp)