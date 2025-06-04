//
// Created by rasmus on 5/8/25.
//

#ifndef WORLD_H
#define WORLD_H

#include "WorldGen.h"
#include "Chunk.h"
#include "Utils.h"
#include "TextureManager.h"

class World {
private:
    std::unordered_map<sf::Vector2i, std::unique_ptr<Chunk>, Utils::Vector2iHash> chunks;

    void newChunk(sf::Vector2i chunkPos);
    TextureManager textureManager;
    WorldGen worldGen;
public:
    World();
    ~World();

    void render(sf::RenderWindow &window);

    Chunk* getChunk(sf::Vector2i chunkPos);
};



#endif //WORLD_H
