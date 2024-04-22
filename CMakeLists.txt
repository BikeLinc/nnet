cmake_minimum_required(VERSION 3.0)
project(nnet)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the build directory to be inside the project folder
set(BUILD_DIR "${CMAKE_SOURCE_DIR}/build")
file(MAKE_DIRECTORY ${BUILD_DIR})

# For macOS, use G++
if(APPLE)
    set(CMAKE_CXX_COMPILER "/usr/bin/g++")
endif()

# For Windows, use Visual Studio
if(WIN32)
    set(CMAKE_GENERATOR "Visual Studio")
endif()

file(GLOB SOURCES "src/*.cpp")

# Output executable to the build directory
set(EXECUTABLE_OUTPUT_PATH ${BUILD_DIR})

add_executable(nnet_exe ${SOURCES})
