//
// Created by rasmus on 5/8/25.
//

#include "include/World.h"

#include <ranges>

void World::newChunk(sf::Vector2i chunkPos) {
    //DUMMY CHUNK!!!
    // std::vector<int> dummyChunkData;
    // dummyChunkData.resize(CHUNK_SIZE * CHUNK_SIZE);
    // for (int x = 0; x < CHUNK_SIZE; ++x) {
    //     for (int y = 0; y < CHUNK_SIZE; ++y) {
    //         if (y < 10) {
    //             dummyChunkData[Utils::chunkPosToIndex(x, y)] = -1;
    //         } else {
    //             dummyChunkData[Utils::chunkPosToIndex(x, y)] = 0;
    //         }
    //     }
    // }
    //
    // this->chunkData.emplace(chunkPos, dummyChunkData);
    std::vector<int> newChunk;
    newChunk.resize(CHUNK_SIZE * CHUNK_SIZE);
    newChunk = worldGen.generateChunk(sf::Vector2i(chunkPos));

    this->chunkData.emplace(chunkPos, newChunk);

    this->chunks.emplace(chunkPos, Chunk(chunkData[chunkPos], textureManager));
    this->chunks.at(chunkPos).move(sf::Vector2f(chunkPos.x * CHUNK_SIZE * TILE_SIZE, chunkPos.y * CHUNK_SIZE * TILE_SIZE));
    //this->chunks.at(chunkPos).move(sf::Vector2f(chunkPos.x*CHUNK_SIZE*TILE_SIZE, chunkPos.y*CHUNK_SIZE*TILE_SIZE));

}

World::World() {
    for (int i = -5; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            newChunk(sf::Vector2i(i, j));
        }
    }
    // chunks.at(sf::Vector2i(0,0)).move({CHUNK_SIZE*TILE_SIZE, 0});
    // chunks.at(sf::Vector2i(1,0)).move({2*CHUNK_SIZE*TILE_SIZE, 0});
}

World::~World() {
}

void World::render(sf::RenderWindow &window) {
    // window.draw(chunks.at(sf::Vector2i(0,0)));
    // window.draw(chunks.at(sf::Vector2i(1,0)));
    for (auto &val: chunks | std::views::values) {
        window.draw(val);
    }
}
