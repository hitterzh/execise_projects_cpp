cmake_minimum_required(VERSION 3.17)
set(CMAKE_c_COMPILER "C:/MinGW/bin/gcc.exe")
set(CMAKE_cxx_COMPILER "C:/MinGW/bin/g++.exe")
project(leptjson_testprj)

set(CMAKE_CXX_STANDARD 14)

add_library(leptjson leptjson.c)
add_executable(leptjson_testprj test.c)
target_link_libraries(leptjson_testprj leptjson)

include_directories("C:/MinGW/include")

