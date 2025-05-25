//
// Created by rasmus on 5/24/25.
//

#include "include/TextureManager.h"

#include <iostream>

void TextureManager::loadTextures() {
    if (!tileSheet.loadFromFile("resources/tilemap3.png")) {
        std::cerr << "Failed to load tile sheet" << std::endl;
    }
}

void TextureManager::setUpStandardCoords() {
    bool up, right, down, left;
    up = right = down = left = false;

    for (int x = 0; x < 4; ++x) {
        switch (x) {
            case 0:
                left = true;
                right = false;
                break;
            case 1:
                left = false;
                right = false;
                break;
            case 2:
                left = false;
                right = true;
                break;
            case 3:
                left = true;
                right = true;
                break;
        }
        for (int y = 0; y < 4; ++y) {
            switch (y) {
                case 0:
                    up = true;
                    down = false;
                    break;
                case 1:
                    up = false;
                    down = false;
                    break;
                case 2:
                    up = false;
                    down = true;
                    break;
                case 3:
                    up = true;
                    down = true;
                    break;
            }

            int bitmask = getBitmask(up, right, down, left);

            this->standardCoords.emplace(bitmask, sf::Vector2i(x*TILE_SPRITE_SIZE, y*TILE_SPRITE_SIZE));
        }
    }
}


int TextureManager::getBitmask(bool up, bool right, bool down, bool left) {
    int bitmask = 0;
    if (up)
        bitmask |= (1 << 0);
    if (right)
        bitmask |= (1 << 1);
    if (down)
        bitmask |= (1 << 2);
    if (left)
        bitmask |= (1 << 3);
    return bitmask;
}

TextureManager::TextureManager() {
    loadTextures();
    setUpStandardCoords();
}

TextureManager::~TextureManager() {
}

sf::Texture & TextureManager::getTexture() {
    return tileSheet;
}

sf::Vector2f TextureManager::getTextureCoords(TileType type, bool up, bool right, bool down, bool left) {
    int yLevel = static_cast<int>(type);
    int bitmask = getBitmask(up, right, down, left);
    sf::Vector2i coords = this->standardCoords.at(bitmask);
    return {static_cast<float>(coords.x), static_cast<float>(coords.y + (yLevel * TILE_SPRITE_SIZE * 4))};
}
