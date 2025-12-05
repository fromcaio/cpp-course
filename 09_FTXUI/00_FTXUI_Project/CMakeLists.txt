cmake_minimum_required(VERSION 3.20)

project(FTXUIProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SQLite3 REQUIRED)
find_package(ftxui REQUIRED)

add_executable(ftxui_example
    main.cpp
)

target_link_libraries(ftxui_example PRIVATE SQLite::SQLite3 ftxui::screen ftxui::dom ftxui::component)