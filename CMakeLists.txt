cmake_minimum_required(VERSION 3.17)
project(Mafs)

set(CMAKE_CXX_STANDARD 14)

add_executable(Mafs main.cpp quanc8.h quanc8.cpp lagrange.cpp lagrange.h SPLINES.H SPLINES.CPP)