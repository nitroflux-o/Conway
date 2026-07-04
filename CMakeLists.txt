cmake_minimum_required(VERSION 3.23)
project(Conway)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
    src/main.cpp



)

add_executable(life ${SOURCES})
target_include_directories(life PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
