//
// Created by rasmus on 5/8/25.
//

#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

enum class TileType {DIRT, GRASS, STONE};

class Tile {
private:
    sf::RectangleShape m_Rect;
    void setType(TileType type);
public:
    Tile(TileType type, float size);
    ~Tile();
    void changeType(TileType type);
    void render(sf::RenderTarget* target);
};



#endif //TILE_H
