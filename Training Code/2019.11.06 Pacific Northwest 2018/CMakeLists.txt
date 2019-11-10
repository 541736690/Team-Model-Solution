cmake_minimum_required(VERSION 3.13)
project(2019_11_06_Pacific_Northwest_2018)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-g -O2 -std=gnu++14 -static -Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(2019_11_06_Pacific_Northwest_2018 I2.cpp)