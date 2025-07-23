cmake_minimum_required(VERSION 3.29) 
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(decision_makers_lib STATIC)

target_sources(decision_makers_lib 
    PRIVATE
    src/DecisionMaker.cpp
)

target_include_directories(decision_makers_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
