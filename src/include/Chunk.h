//
// Created by rasmus on 5/21/25.
//

#ifndef CHUNK_H
#define CHUNK_H

#include <vector>
#include <iostream>

#include "Tile.h"
#include "Config.h"
//#include "Utils.h"

class World;
class WorldGen;
class TextureManager;

class Chunk : public sf::Drawable, public sf::Transformable {
private:
    //Tiles
    std::vector<Tile> tiles;
    void updateTileNeighbours();

    //Variables
    const sf::Vector2i position;
    void printPosition();

    //Textures
    TextureManager &textureManager;
    sf::Texture *texture;

    //Neighbors
    Chunk *m_Up = nullptr;
    Chunk *m_Right = nullptr;
    Chunk *m_Down = nullptr;
    Chunk *m_Left = nullptr;

    //Rendering
    sf::VertexArray m_Vertices;
    sf::RenderStates m_RenderStates;
    sf::Transform m_Transform;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    //Constructor and destructor
    explicit Chunk(sf::Vector2i chunkPos, WorldGen &generator, TextureManager &textureManager);
    ~Chunk();

    //Functions
    void setChunkNeighbors(World &world);
    void updateVertices();
    void updateTextures();

    //Tile functions
    Tile &getTileAt(sf::Vector2i pos);

};



#endif //CHUNK_H
