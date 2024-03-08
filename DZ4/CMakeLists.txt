cmake_minimum_required(VERSION 3.22)
project(Graphs)

add_executable(time ../src/slo_oe/DenseCSR.cpp ../src/slo_oe/SIMs.cpp Timespeed.cpp)
add_executable(iterations ../src/slo_oe/DenseCSR.cpp ../src/slo_oe/SIMs.cpp Iterationes.cpp)
