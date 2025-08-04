cmake_minimum_required(VERSION 3.29) 
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(characters_lib STATIC)

target_sources(characters_lib
    PUBLIC 
    src/Character.cpp
    src/NPC.cpp
    src/Player.cpp
    src/Team.cpp
    src/Stats.cpp
    src/Action.cpp
    src/Attack.cpp
    src/TeamContainer.cpp
)

target_link_libraries(characters_lib PUBLIC nlohmann_json::nlohmann_json)
target_link_libraries(characters_lib PRIVATE decision_lib)
target_include_directories(characters_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
