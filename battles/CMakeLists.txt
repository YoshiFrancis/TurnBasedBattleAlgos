cmake_minimum_required(VERSION 3.29) 
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(battles_lib STATIC)

target_sources(battles_lib 
    PUBLIC
    src/BattleArena.cpp
)

add_executable(battles main.cpp)
