cmake_minimum_required(VERSION 3.19)
project(Compiler C)

set(CMAKE_C_STANDARD 11)

add_executable(Compiler main.c A.c A.h util.c util.h)