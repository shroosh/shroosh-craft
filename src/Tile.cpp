//
// Created by rasmus on 5/21/25.
//

#include "include/Tile.h"

Tile::Tile(const TileType type) : m_Type(type) {
}

Tile::~Tile() {
}

TileType Tile::getType() const {
    return m_Type;
}

Tile & Tile::up() {
    return *upTile;
}

Tile & Tile::right() {
    return *rightTile;
}

Tile & Tile::down() {
    return *downTile;
}

Tile & Tile::left() {
    return *leftTile;
}

void Tile::up(Tile &neighbor) {
    this->upTile = &neighbor;
}

void Tile::right(Tile &neighbor) {
    this->rightTile = &neighbor;
}

void Tile::down(Tile &neighbor) {
    this->downTile = &neighbor;
}

void Tile::left(Tile &neighbor) {
    this->leftTile = &neighbor;
}
