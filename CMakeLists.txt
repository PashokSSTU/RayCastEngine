cmake_minimum_required(VERSION 3.0)

project(raycast_engine)

#include_directories(raylib/src)

add_subdirectory(engine)
add_subdirectory(raylib)

#add_executable(raycast_engine main.cpp)

#target_link_libraries(raycast_engine PRIVATE raylib)