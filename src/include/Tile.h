//
// Created by rasmus on 5/21/25.
//

#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include "TileType.h"
#include "Config.h"

class Tile {
private:
    TileType m_Type;

    //Neighbors
    Tile *upTile;
    Tile *rightTile;
    Tile *downTile;
    Tile *leftTile;
public:
    explicit Tile(TileType type);
    ~Tile();

    TileType getType() const;


    Tile& up();
    Tile& right();
    Tile& down();
    Tile& left();

    void up(Tile& neighbor);
    void right(Tile& neighbor);
    void down(Tile& neighbor);
    void left(Tile& neighbor);
};



#endif //TILE_H
