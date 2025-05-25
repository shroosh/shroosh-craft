//
// Created by rasmus on 5/21/25.
//

#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

enum class TileType {
    AIR = -1, GRASS, DIRT, STONE
};

constexpr unsigned short TILE_SIZE = 64;

class Tile {
private:
    TileType type;
    sf::Vector2i pos;

    bool up;
    bool right;
    bool down;
    bool left;
public:
    Tile(TileType type, sf::Vector2i pos);
    ~Tile();

    void setType(TileType);
    TileType getType();

    sf::Vector2i getPos() const;

    void setUp(bool air);
    void setRight(bool air);
    void setDown(bool air);
    void setLeft(bool air);

    bool getUp();
    bool getRight();
    bool getDown();
    bool getLeft();
};



#endif //TILE_H
