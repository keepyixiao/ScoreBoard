cmake_minimum_required(VERSION 3.19)
project(ScoreBoard)

MESSAGE(STATUS "CMAKE_CURRETN_SOURCE_DIR is ${CMAKE_CURRENT_SOURCE_DIR}")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(lib)
add_executable(ScoreBoard main.cpp)