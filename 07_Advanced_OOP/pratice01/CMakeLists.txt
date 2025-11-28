cmake_minimum_required(VERSION 3.14)
project(TelemetryProcessor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Dependency Management ---
include(FetchContent)
set(JSON_BuildTests OFF CACHE INTERNAL "")
FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
)
FetchContent_MakeAvailable(json)

# --- Project Setup ---
add_executable(telemetry_processor
    src/main.cpp
    src/sensor.cpp
    src/utils.cpp
)

target_include_directories(telemetry_processor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(telemetry_processor PRIVATE PROJECT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(telemetry_processor PRIVATE nlohmann_json::nlohmann_json)
