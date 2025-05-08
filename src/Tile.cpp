//
// Created by rasmus on 5/8/25.
//

#include "include/Tile.h"

void Tile::setType(TileType type) {
    switch (type) {
        case TileType::DIRT:
            this->m_Rect.setFillColor(sf::Color(110, 59, 11));
        case TileType::GRASS:
            this->m_Rect.setFillColor(sf::Color::Green);
        case TileType::STONE:
            this->m_Rect.setFillColor(sf::Color(134, 134, 134));
    }
}

Tile::Tile(TileType type, float size) {
    this->setType(type);
    this->m_Rect.setSize({size, size});
}

Tile::~Tile() {
}

void Tile::changeType(TileType type) {
    this->setType(type);
}

void Tile::render(sf::RenderTarget* target) {
    target->draw(this->m_Rect);
}
