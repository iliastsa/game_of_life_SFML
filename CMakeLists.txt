cmake_minimum_required(VERSION 2.7)

project(game_of_life_SFML)

set(PROJECT_BINARY_DIR "${CMAKE_SOURCE_DIR}/build")

set(EXECUTABLE_NAME "game_of_life")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

add_subdirectory(src)
