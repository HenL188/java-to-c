cmake_minimum_required(VERSION 3.31)
project(java_to_c)

set(CMAKE_CXX_STANDARD 20)

add_executable(java_to_c main.cpp Lexer.cpp)
