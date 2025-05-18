//
// Created by rasmus on 5/12/25.
//

#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>

static constexpr unsigned short CHUNK_SIZE = 40;
static constexpr float TILE_SIZE = 64.f;

class TileMap : public sf::Drawable, public sf::Transformable {
private:
    sf::VertexArray m_vertices;
    void initVertices(int mapData[CHUNK_SIZE][CHUNK_SIZE]);

    sf::RenderStates m_state;
    sf::Texture *p_texture;
    sf::Transform m_transform;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    TileMap(int mapData[CHUNK_SIZE][CHUNK_SIZE], sf::Texture *p_texture);
    ~TileMap();
};



#endif //TILEMAP_H
