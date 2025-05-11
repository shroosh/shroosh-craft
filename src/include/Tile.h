//
// Created by rasmus on 5/8/25.
//

#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <map>
#include <iostream>

enum class TileType {DIRT, GRASS, STONE, AIR};

class Tile {
private:
    sf::RectangleShape m_Rect;
    TileType m_Type;
    void setType(TileType type);
public:
    Tile(TileType type, float size, float posX, float posY);
    Tile(TileType type);
    ~Tile();
    void changeType(TileType type);
    void render(sf::RenderTarget* target);
};



#endif //TILE_H
