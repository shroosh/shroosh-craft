//
// Created by rasmus on 5/24/25.
//

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Tile.h"
#include "TileType.h"

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

    sf::Texture *getTexture();

    sf::Vector2f getTextureCoords(TileType type, Tile &upTile, Tile &rightTile, Tile &downTile, Tile &leftTile);
};

#endif //TEXTUREMANAGER_H
