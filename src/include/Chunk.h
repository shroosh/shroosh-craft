//
// Created by rasmus on 5/14/25.
//

#ifndef CHUNK_H
#define CHUNK_H
#include <vector>
#include <noise/noise.h>
#include <iostream>
#include "TileTypes.h"
#include <SFML/Graphics.hpp>

static constexpr unsigned short CHUNK_SIZE = 40;
static constexpr float TILE_SIZE = 64.f;

class Chunk : public sf::Drawable, public sf::Transformable {
private:
    sf::Vector2i position;

    sf::VertexArray m_vertices;
    sf::RenderStates m_state;
    sf::Transform m_transform;

    void initVertices();

    void setTile(int x, int y, sf::Color color);
    void updateTileTextures();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    std::vector<std::vector< TileType>> tiles{CHUNK_SIZE, std::vector<TileType>(CHUNK_SIZE, TileType::AIR)};
    void generateTileData(std::array<int, CHUNK_SIZE> heights);
public:
    Chunk(sf::Vector2i chunkPos, std::array<int, CHUNK_SIZE> heights);
    ~Chunk();
};



#endif //CHUNK_H
