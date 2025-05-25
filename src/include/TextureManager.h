//
// Created by rasmus on 5/24/25.
//

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <unordered_map>
#include <SFML/Graphics/Texture.hpp>
#include "Utils.h"

#include "Tile.h"

constexpr int TILE_VARIANTS = 15;
constexpr int TILE_SPRITE_SIZE = 16;

class TextureManager {
private:
    void loadTextures();
    sf::Texture tileSheet;

    void setUpStandardCoords();
    std::unordered_map<int, sf::Vector2i> standardCoords;

    int getBitmask(bool up, bool right, bool down, bool left);

public:
    TextureManager();
    ~TextureManager();

    sf::Texture& getTexture();

    sf::Vector2f getTextureCoords(TileType type, bool up, bool right, bool down, bool left);
};

#endif //TEXTUREMANAGER_H
