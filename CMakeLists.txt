cmake_minimum_required(VERSION 3.10)

project(Simple-Keylogger LANGUAGES CXX)

find_package(SDL2 REQUIRED CONFIG)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(keylogger SDL_input_reader.cpp)

target_link_libraries(keylogger ${SDL2_LIBRARIES})
