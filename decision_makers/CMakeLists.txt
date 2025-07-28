cmake_minimum_required(VERSION 3.29) 
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(decision_lib STATIC)

target_sources(decision_lib 
    PRIVATE
    src/DecisionMaker.cpp
    src/dm.cpp
    src/TestAutoInput.cpp
)

target_link_libraries(decision_lib PRIVATE characters_lib)
target_include_directories(decision_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
