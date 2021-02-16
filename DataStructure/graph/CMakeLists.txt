cmake_minimum_required(VERSION 3.17)
project(graph)

set(CMAKE_CXX_STANDARD 11)

add_executable(graph graph.cpp tarjan.cpp exercises/USACO08DEC.cpp kosaraju.cpp)