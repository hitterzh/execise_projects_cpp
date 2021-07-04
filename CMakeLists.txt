cmake_minimum_required(VERSION 3.17)
set(CMAKE_c_COMPILER "C:/MinGW/bin/gcc.exe")
set(CMAKE_cxx_COMPILER "C:/MinGW/bin/g++.exe")
project(leptjson_testprj)

set(CMAKE_CXX_STANDARD 14)

add_library(leptjson leptjson.c )
#add_executable(leptjson_testprj test.c)
add_executable(overload_brackets cppthings/overload_brackets.cpp)
add_executable(overload_pp cppthings/overload_pp.cpp)
add_executable(overload_cast cppthings/overload_cast.cpp)
add_executable(func_template cppthings/func_template.cpp)
add_executable(dict cppthings/dict.cpp)
add_executable(cppstd cppstdlib/stl_routine.cpp)
#target_link_libraries(leptjson_testprj leptjson)

include_directories("C:/MinGW/include")


# for python vm
add_executable(railgun pythonvm/main.cpp
        pythonvm/util/map.cpp)
