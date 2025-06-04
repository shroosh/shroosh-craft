//
// Created by rasmus on 5/8/25.
//

#include "include/WorldGen.h"

#include <iostream>

void WorldGen::initPerlin() {
    this->singlePerlin.SetFrequency(0.1);
    this->singlePerlin.SetPersistence(0.15);
    this->singlePerlin.SetLacunarity(2.0);
    this->singlePerlin.SetOctaveCount(3);

    this->singlePerlin.SetSeed(237891);

    this->doublePerlin.SetFrequency(0.3);
    this->doublePerlin.SetPersistence(0.15);
    this->doublePerlin.SetLacunarity(2.0);
    this->doublePerlin.SetOctaveCount(5);

    this->doublePerlin.SetSeed(237891);
}

WorldGen::WorldGen() {
    this->initPerlin();
}

WorldGen::~WorldGen() {
}

std::vector<Tile> WorldGen::generate(sf::Vector2i pos) {
    std::vector<Tile> tiles;
    tiles.resize(CHUNK_SIZE * CHUNK_SIZE, Tile(TileType::AIR));
    int startX = pos.x * CHUNK_SIZE;
    int startY = pos.y * CHUNK_SIZE;

    if (pos.y == 1) {
        for (int x = 0; x < CHUNK_SIZE; x++) {
            const double groundLevelNoise = this->singlePerlin.GetValue(0.2 * (x + startX), 0.0, 0.0);
            const double stoneLevelNoise = this->singlePerlin.GetValue(0.2 * (x + startX), 0.0, 0.0);
            const int groundLevel = static_cast<int>((groundLevelNoise + 1) * (CHUNK_SIZE) / 2);
            const int stoneLevel = CHUNK_SIZE - 1 - static_cast<int>((stoneLevelNoise + 1) * (groundLevel) / 2);

            //Air
            for (int y = 0; y < groundLevel; y++) {
                const Tile air(TileType::AIR);
                tiles[x + CHUNK_SIZE * y] = air;
            }
            tiles[x + groundLevel * CHUNK_SIZE] = Tile(TileType::GRASS);
            for (int y = groundLevel + 1; y < stoneLevel; y++) {
                const Tile dirt(TileType::DIRT);
                tiles[x + CHUNK_SIZE * y] = dirt;
            }
            for (int y = stoneLevel; y < CHUNK_SIZE; y++) {
                const Tile stone(TileType::STONE);
                tiles[x + CHUNK_SIZE * y] = stone;
            }
        }
    } else {
        for (int i = 0; i < CHUNK_SIZE * CHUNK_SIZE; i++) {
            Tile tile(TileType::AIR);
            tiles.push_back(tile);
        }
    }

    return tiles;
}
