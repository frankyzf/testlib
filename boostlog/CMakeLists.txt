cmake_minimum_required(VERSION 3.3)
project(boostlog)

include_directories("/usr/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DBOOST_LOG_DYN_LINK")



set(SOURCE_FILES main.cpp)
add_executable(boostlog ${SOURCE_FILES})

target_link_libraries(boostlog pthread)
target_link_libraries(boostlog boost_log)