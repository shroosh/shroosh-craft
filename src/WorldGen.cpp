//
// Created by rasmus on 5/8/25.
//

#include "include/WorldGen.h"

#include "include/Chunk.h"

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

std::vector<int> WorldGen::generateChunk(sf::Vector2i pos) {
    std::vector<int> chunk;
    chunk.resize(CHUNK_SIZE * CHUNK_SIZE, static_cast<int>(TileType::AIR));

    //AIR CHUNK
    if (pos.y == 0) {
        return chunk;
    }

    int startingX = pos.x * CHUNK_SIZE;
    int startingY = pos.y * CHUNK_SIZE;

    //GROUND CHUNK
    if (pos.y == 1) {
        for (int x = 0; x < CHUNK_SIZE; x++) {
            double noise = this->singlePerlin.GetValue(0.2 * (x + startingX), 0.0, 0.0);
            int groundLevel = static_cast<int>((noise + 1) * CHUNK_SIZE / 2);
            chunk[Utils::chunkPosToIndex(x, groundLevel)] = static_cast<int>(TileType::GRASS);
            for (int y = groundLevel + 1; y < CHUNK_SIZE; y++) {
                chunk[Utils::chunkPosToIndex(x, y)] = static_cast<int>(TileType::DIRT);
            }
            noise = this->singlePerlin.GetValue(0.2 * (x + startingX + 7123), 0.0, 0.0);
            int stoneLevel = static_cast<int>(30 + (noise + 1) * 10 / 2);
            for (int y = stoneLevel; y < CHUNK_SIZE; y++) {
                chunk[Utils::chunkPosToIndex(x, y)] = static_cast<int>(TileType::STONE);
            }
        }

        return chunk;
    }

    if (pos.y == 2) {
        for (int x = 0; x < CHUNK_SIZE; x++) {
            for (int y = 0; y < CHUNK_SIZE; y++) {
                double noise = doublePerlin.GetValue(0.1 * (x + startingX), 0.3 * (y + startingY), 0.0);
                if (noise  < 0.3 + 5.f/y) {
                    chunk[Utils::chunkPosToIndex(x, y)] = static_cast<int>(TileType::STONE);
                }
                //chunk[Utils::chunkPosToIndex(x, y)] = static_cast<int>(TileType::STONE);
            }
        }
        return chunk;
    }

    if (pos.y > 2) {
        for (int x = 0; x < CHUNK_SIZE; x++) {
            for (int y = 0; y < CHUNK_SIZE; y++) {
                double noise = doublePerlin.GetValue(0.1 * (x + startingX), 0.3 * (y + startingY), 0.0);
                if (noise < 0.3) {
                    chunk[Utils::chunkPosToIndex(x, y)] = static_cast<int>(TileType::STONE);
                }
                //chunk[Utils::chunkPosToIndex(x, y)] = static_cast<int>(TileType::STONE);
            }
        }
        return chunk;
    }

}
