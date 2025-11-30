cmake_minimum_required(VERSION 3.14)

# Project Name and Version
project(GymManagement VERSION 0.1)

# Specify C++ Standard
# In C, you might use -std=c99. Here we enforce C++17.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define include directories
# This is equivalent to the -I./include flag in GCC
# PUBLIC means: "I use this, and anyone linking to me uses this"
include_directories(include)

find_package(SQLite3 REQUIRED)

# Create the Executable
# Syntax: add_executable(Name SourceFiles...)
add_executable(gym_management 
    src/main.cpp 
    src/Exercise.cpp
    src/WorkoutPlan.cpp
    src/Payment.cpp
    src/CheckIn.cpp
    src/Member.cpp
    src/Database.cpp
)

target_link_libraries(gym_management PRIVATE SQLite::SQLite3)
