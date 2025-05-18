//
// Created by rasmus on 5/8/25.
//

#ifndef WORLD_H
#define WORLD_H

#include "Chunk.h"
#include "Player.h"
#include "Vector2iHash.h"

static constexpr unsigned short WORLD_WIDTH = 4000;
static constexpr unsigned short WORLD_HEIGHT = 1000;

class World {
private:
    sf::Texture m_tileset;
    void initTileTextures();

    noise::module::Perlin m_perlin;
    float m_singlePerlinFrequency;
    float m_singlePerlinPersistence;
    float m_singlePerlinLacunarity;
    int m_singlePerlinOctaveCount;
    int m_singlePerlinSeed;

    void initSinglePerlin();
    std::array<int, CHUNK_SIZE> generateTopChunkHeights(int startingPosX);

    Chunk *myChunk;
    std::unordered_map<sf::Vector2i, Chunk, Vector2iHash> chunks;
    void newChunk(sf::Vector2i chunkPosition);
public:
    World();
    ~World();
    void render(sf::RenderTarget& target);
};

#endif //WORLD_H
