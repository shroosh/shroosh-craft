cmake_minimum_required(VERSION 3.31)

project(shroosh_craft)

set(CMAKE_CXX_STANDARD 20)

add_executable(shroosh_craft src/main.cpp
        src/Game.cpp
        src/include/Game.h
        src/World.cpp
        src/include/World.h
        src/TileMap.cpp
        src/include/TileMap.h
        src/Chunk.cpp
        src/include/Chunk.h
        src/include/TileTypes.h
        src/Player.cpp
        src/include/Player.h
        src/include/Vector2iHash.h
)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio Network)

target_link_libraries(shroosh_craft PRIVATE PRIVATE SFML::Graphics SFML::Audio SFML::Network noise)
