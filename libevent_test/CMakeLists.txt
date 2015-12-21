cmake_minimum_required(VERSION 3.3)
project(libevent_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(/mnt/home/feng/workspace/lib/libevent/tmp/include)
include_directories(/mnt/home/feng/workspace/lib/libevent/include)

set(SOURCE_FILES main.cpp)
add_executable(libevent_test ${SOURCE_FILES})
target_link_libraries(libevent_test /mnt/home/feng/workspace/lib/libevent/tmp/lib/libevent.a)