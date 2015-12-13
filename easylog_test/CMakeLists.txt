cmake_minimum_required(VERSION 3.3)
project(easylog_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories("/mnt/home/feng/workspace/lib/easyloggingpp/src")
set(SOURCE_FILES main.cpp)
add_executable(easylog_test ${SOURCE_FILES})