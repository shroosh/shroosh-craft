//
// Created by rasmus on 5/8/25.
//

#include "include/Tile.h"

void Tile::setType(TileType type) {
    this->m_Type = type;
    switch (type) {
        case TileType::DIRT:
            this->m_Rect.setFillColor(sf::Color(110, 59, 11));
            break;
        case TileType::GRASS:
            this->m_Rect.setFillColor(sf::Color::Green);
            break;
        case TileType::STONE:
            this->m_Rect.setFillColor(sf::Color(134, 134, 134));
            break;
        case TileType::AIR:
            break;
    }
}

Tile::Tile(TileType type, float size, float posX, float posY) {
    this->setType(type);
    this->m_Rect.setSize({size, size});
    this->m_Rect.setPosition({posX * size, posY * size});
}

Tile::Tile(TileType type) {
    this->setType(type);
}

Tile::~Tile() {
}

void Tile::changeType(TileType type) {
    this->setType(type);
}

void Tile::render(sf::RenderTarget* target) {
    if (this->m_Type != TileType::AIR) {
        target->draw(this->m_Rect);
    }
}