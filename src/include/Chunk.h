//
// Created by rasmus on 5/21/25.
//

#ifndef CHUNK_H
#define CHUNK_H

#include <vector>
#include <iostream>

#include "Tile.h"
#include "Utils.h"

static constexpr unsigned short CHUNK_SIZE = 40;

class TextureManager;

class Chunk : public sf::Drawable, public sf::Transformable {
private:
    std::vector<Tile> tiles;
    std::vector<int> &tileData;

    sf::VertexArray vertices;
    sf::RenderStates renderStates;
    sf::Transform transform;

    TextureManager &textureManager;
    sf::Texture *texture;

    void updateTile(Tile &tile);
    void setTileNeighbors(Tile &tile);
    void updateTileTexture(Tile &tile);
    void setVertices(Tile &tile);

    void load();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    explicit Chunk(std::vector<int> &tiles, TextureManager &textureManager);
    ~Chunk();
};



#endif //CHUNK_H
