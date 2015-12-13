cmake_minimum_required(VERSION 3.3)
project(rapidjson_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories("/mnt/home/feng/workspace/lib/rapidjson/include")
set(SOURCE_FILES main.cpp)
add_executable(rapidjson_test ${SOURCE_FILES})