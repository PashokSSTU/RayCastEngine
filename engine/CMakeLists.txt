cmake_minimum_required(VERSION 3.0)
#project(raycast_engine)

add_executable(raycast_engine main.cpp)

target_link_libraries(raycast_engine PRIVATE raylib)