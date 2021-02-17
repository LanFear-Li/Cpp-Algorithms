cmake_minimum_required(VERSION 3.17)
project(graph)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        graph
        N2_Basic/topolpgicalSort.cpp
        N2_Basic/tarjan.cpp
        N2_Basic/kosaraju.cpp
        N3_MinimumSpanningTree/kruskal.cpp
        N1_Exercises/P3366.cpp
        N3_MinimumSpanningTree/prim.cpp
)