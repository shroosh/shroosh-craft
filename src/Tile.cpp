//
// Created by rasmus on 5/21/25.
//

#include "include/Tile.h"

Tile::Tile(TileType type, sf::Vector2i pos) : type(type), pos(pos) {
    //this->up = this->down = this->left = this->right = false;
}

Tile::~Tile() {
}

void Tile::setType(TileType) {
}

TileType Tile::getType() {
    return type;
}

sf::Vector2i Tile::getPos() const {
    return pos;
}

void Tile::setUp(bool air) {
    up = air;
}

void Tile::setRight(bool air) {
    right = air;
}

void Tile::setDown(bool air) {
    down = air;
}

void Tile::setLeft(bool air) {
    left = air;
}

bool Tile::getUp() {
    return up;
}

bool Tile::getRight() {
    return right;
}

bool Tile::getDown() {
    return down;
}

bool Tile::getLeft() {
    return left;
}
