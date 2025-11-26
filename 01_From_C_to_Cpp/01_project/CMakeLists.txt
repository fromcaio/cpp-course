cmake_minimum_required(VERSION 3.10)

# Project Name and Version
project(SimpleCalculator VERSION 1.0)

# Specify C++ Standard
# In C, you might use -std=c99. Here we enforce C++17.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define include directories
# This is equivalent to the -I./include flag in GCC
# PUBLIC means: "I use this, and anyone linking to me uses this"
include_directories(include)

# Create the Executable
# Syntax: add_executable(Name SourceFiles...)
add_executable(calculator 
    src/main.cpp 
    src/simple_math.cpp
)