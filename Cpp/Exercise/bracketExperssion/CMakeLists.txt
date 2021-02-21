cmake_minimum_required(VERSION 3.17)
project(bracketExpression)

set(CMAKE_CXX_STANDARD 11)

add_executable(bracketExpression test.cpp expressionTree.cpp expressionTree.h)