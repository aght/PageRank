cmake_minimum_required(VERSION 3.12)
project(PageRank)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_executable(PageRank main.cpp Matrix.cpp Matrix.hpp TextFileReader.cpp TextFileReader.hpp PageRank.cpp PageRank.hpp)