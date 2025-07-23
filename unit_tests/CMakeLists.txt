cmake_minimum_required(VERSION 3.29) 
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(unit_tests)

target_sources(unit_tests
    PRIVATE
    test_battles.cpp
    test_characters.cpp
    test_decision_makers.cpp
)

target_link_libraries(unit_tests PRIVATE characters_lib battles_lib decision_makers_lib)

include(GoogleTest)
gtest_discover_tests(unit_tests DISCOVERY_MODE PRE_TEST)
