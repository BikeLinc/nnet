cmake_minimum_required(VERSION 3.0)
project(nnet) 

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "src/*.cpp")

add_executable(nnet_exe ${SOURCES})
