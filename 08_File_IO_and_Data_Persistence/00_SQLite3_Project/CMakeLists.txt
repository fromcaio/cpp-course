cmake_minimum_required(VERSION 3.20)

project(SQLite3Project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SQLite3 REQUIRED)

add_executable(sqlite3_example
    main.cpp
)

target_link_libraries(sqlite3_example PRIVATE SQLite::SQLite3)
