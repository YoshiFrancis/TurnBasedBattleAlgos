
cmake_minimum_required(VERSION 3.10)
project(TurnBasedBattles)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(GTest REQUIRED)

add_subdirectory(decision_makers)
add_subdirectory(characters)
add_subdirectory(battles)
