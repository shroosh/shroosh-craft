//
// Created by rasmus on 5/8/25.
//

#include "include/World.h"

#include <ranges>

void World::newChunk(sf::Vector2i chunkPos) {
    //Generate chunk.
    if (!chunks.contains(chunkPos)) {
        chunks[chunkPos] = std::make_unique<Chunk>(chunkPos, worldGen, textureManager);
    }

    //Make an array of cardinal neighbors
    const std::array<sf::Vector2i, 4> cardinals = {
        sf::Vector2i{0, -1},
        sf::Vector2i{1, 0},
        sf::Vector2i{0, 1},
        sf::Vector2i{-1, 0}
    };

    //Generate neighbours.
    for (const auto& cardinal: cardinals) {
        sf::Vector2i neighborPos = chunkPos + cardinal;
        if (!chunks.contains(neighborPos)) {
            chunks[neighborPos] = std::make_unique<Chunk>(neighborPos, worldGen, textureManager);
        }
    }

    //Update the chunks neighbors and textures.
    if (chunks.contains(chunkPos)) {
        chunks[chunkPos]->setChunkNeighbors(*this);
        chunks[chunkPos]->updateVertices();
        chunks[chunkPos]->updateTextures();
    }
}

World::World() {
    newChunk(sf::Vector2i{0, 1});
    newChunk(sf::Vector2i{1, 1});
    chunks[sf::Vector2i{1, 1}]->move({CHUNK_SIZE * TILE_SIZE, 0});
}

World::~World() {
}

void World::render(sf::RenderWindow &window) {
    window.draw(*chunks[{0, 1}]);
    window.draw(*chunks[{1, 1}]);
    // window.draw(chunks.at(sf::Vector2i(1,0)));

}

Chunk * World::getChunk(sf::Vector2i chunkPos) {
    if (chunks.contains(chunkPos)) {
        return chunks[chunkPos].get();
    }
    return nullptr;
}
