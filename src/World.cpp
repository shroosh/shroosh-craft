//
// Created by rasmus on 5/8/25.
//

#include "include/World.h"

#include <iostream>


void World::initTileTextures() {
    if (!m_tileset.loadFromFile("resources/dirtsheet.png")) {
        throw sf::Exception("Failed to load tileset");
    }
}

void World::initSinglePerlin() {
    this->m_singlePerlinFrequency = 0.15;
    this->m_singlePerlinPersistence = 0.2;
    this->m_singlePerlinLacunarity = 3.0;
    this->m_singlePerlinOctaveCount = 5;

    this->m_singlePerlinSeed = 874323;

    this->m_perlin.SetFrequency(this->m_singlePerlinFrequency);
    this->m_perlin.SetPersistence(this->m_singlePerlinPersistence);
    this->m_perlin.SetLacunarity(this->m_singlePerlinLacunarity);
    this->m_perlin.SetOctaveCount(this->m_singlePerlinOctaveCount);
    this->m_perlin.SetSeed(this->m_singlePerlinSeed);
}

std::array<int, CHUNK_SIZE> World::generateTopChunkHeights(int startingPosX) {
    std::array<int, CHUNK_SIZE> topChunkHeights;
    for (int x = 0; x < CHUNK_SIZE; x++) {
        double noise = this->m_perlin.GetValue((x + startingPosX * CHUNK_SIZE) * 0.1, 0.0, 0.0);
        topChunkHeights[x] = static_cast<int>((noise + 1) * CHUNK_SIZE / 2);
    }
    return topChunkHeights;
}

void World::newChunk(sf::Vector2i chunkPosition) {
    Chunk newChunk(chunkPosition, generateTopChunkHeights(chunkPosition.x));
    chunks.emplace(chunkPosition, newChunk);
    std::cout << chunks.size() << std::endl;
}

World::World() {
    this->initTileTextures();
    this->initSinglePerlin();
    for (int x = -50; x < 50; x++) {
        newChunk(sf::Vector2i(x, 0));
    }
    //myChunk = new Chunk(sf::Vector2i(0, 0), generateTopChunkHeights());
}

World::~World() {
}

void World::render(sf::RenderTarget& target) {
    //target.draw(this->m_tilemap);
    //target.draw(*myChunk);
    Chunk &chunk = chunks.at(sf::Vector2i(0, 0));
    // target.draw(chunks.at(sf::Vector2i(0, 0)));
    // target.draw(chunks.at(sf::Vector2i(1, 0)));
    for (int x = -50; x < 50; x++) {
        target.draw(chunks.at(sf::Vector2i(x, 0)));
    }

};