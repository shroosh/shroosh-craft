//
// Created by rasmus on 5/21/25.
//
#include "include/Chunk.h"

#include "include/World.h"
#include "include/WorldGen.h"

void Chunk::updateTileNeighbours() {
    for (int x = 0; x < CHUNK_SIZE; ++x) {
        for (int y = 0; y < CHUNK_SIZE; ++y) {
            Tile &tile = tiles[x + y * CHUNK_SIZE];

            //Up
            tile.up(this->getTileAt({ x, y - 1 }));
            //Right
            tile.right(this->getTileAt({ x + 1, y }));
            //Down
            tile.down(this->getTileAt({ x, y + 1 }));
            //Left
            tile.left(this->getTileAt({ x - 1, y }));
        }
    }
}

void Chunk::printPosition() {
    std::cout << position.x << " " << position.y << std::endl;
}

void Chunk::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = texture;
    target.draw(m_Vertices, states);
}

Chunk::Chunk(const sf::Vector2i chunkPos, WorldGen &generator, TextureManager &textureManager) : position(chunkPos), textureManager(textureManager){
    this->tiles = generator.generate(chunkPos);
    this->m_Vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    this->m_Vertices.resize(CHUNK_SIZE * CHUNK_SIZE * 6);
}

Chunk::~Chunk() {
    for (auto it = tiles.begin(); it != tiles.end(); it++) {
        tiles.erase(it);
    }
}

void Chunk::setChunkNeighbors(World &world) {
    //Set neighbors
    this->m_Up = world.getChunk(this->position + sf::Vector2i(0, -1));
    this->m_Left = world.getChunk(this->position + sf::Vector2i(-1, 0));
    this->m_Down = world.getChunk(this->position + sf::Vector2i(0, 1));
    this->m_Right = world.getChunk(this->position + sf::Vector2i(1, 0));

    //Update tile neighbors
    this->updateTileNeighbours();

}

void Chunk::updateVertices() {
    for (int x = 0; x < CHUNK_SIZE; ++x) {
        for (int y = 0; y < CHUNK_SIZE; ++y) {
            if (tiles[x + y * CHUNK_SIZE].getType() != TileType::AIR) {
                sf::Vertex* vertex = &m_Vertices[(y * CHUNK_SIZE + x) * 6];

                vertex[0].position = {static_cast<float>(x * TILE_SIZE), static_cast<float>(y * TILE_SIZE)}; //0, 0
                vertex[1].position = {static_cast<float>((x + 1) * TILE_SIZE), static_cast<float>(y * TILE_SIZE)}; //1, 0
                vertex[2].position = {static_cast<float>(x * TILE_SIZE), static_cast<float>((y + 1) * TILE_SIZE)}; //0, 1
                vertex[3].position = {static_cast<float>((x + 1) * TILE_SIZE), static_cast<float>((y + 1) * TILE_SIZE)}; //1, 1
                vertex[4].position = {static_cast<float>(x * TILE_SIZE), static_cast<float>((y + 1) * TILE_SIZE)}; //0, 1
                vertex[5].position = {static_cast<float>((x + 1) * TILE_SIZE), static_cast<float>(y * TILE_SIZE)}; //1, 0
            }
        }
    }
}

void Chunk::updateTextures() {
    //Load texture
    if (!texture) {
        texture = this->textureManager.getTexture();
        this->m_RenderStates.texture = texture;
    }

    //Apply the right texture for each tile
    // for (int x = 0; x < CHUNK_SIZE; ++x) {
    //     for (int y = 0; y < CHUNK_SIZE; ++y) {
    //         if (tiles[x + y * CHUNK_SIZE].getType() != TileType::AIR) {
    //             sf::Vertex* vertex = &m_Vertices[(y * CHUNK_SIZE + x) * 6];
    //             sf::Vector2f textureCoordinate = textureManager.getTextureCoords(TileType::DIRT, tiles[0], tiles[0], tiles[0], tiles[0]);
    //
    //             vertex[0].texCoords = textureCoordinate; //0, 0
    //             vertex[1].texCoords = {textureCoordinate.x + TILE_SPRITE_SIZE, textureCoordinate.y}; //1, 0
    //             vertex[2].texCoords = {textureCoordinate.x, textureCoordinate.y + TILE_SPRITE_SIZE}; //0, 1
    //             vertex[3].texCoords = {textureCoordinate.x + TILE_SPRITE_SIZE, textureCoordinate.y + TILE_SPRITE_SIZE}; //1,1
    //             vertex[4].texCoords = {textureCoordinate.x, textureCoordinate.y + TILE_SPRITE_SIZE}; //0, 1
    //             vertex[5].texCoords = {textureCoordinate.x + TILE_SPRITE_SIZE, textureCoordinate.y}; //1, 0
    //         }
    //     }
    // }

    for (int i = 0; i < CHUNK_SIZE * CHUNK_SIZE; ++i) {
        sf::Vertex* vertex = &m_Vertices[i * 6];
        sf::Vector2f textureCoordinate = textureManager.getTextureCoords(tiles[i].getType(), tiles[i].up(), tiles[i].right(), tiles[i].down(), tiles[i].left());

        vertex[0].texCoords = textureCoordinate; //0, 0
        vertex[1].texCoords = {textureCoordinate.x + TILE_SPRITE_SIZE, textureCoordinate.y}; //1, 0
        vertex[2].texCoords = {textureCoordinate.x, textureCoordinate.y + TILE_SPRITE_SIZE}; //0, 1
        vertex[3].texCoords = {textureCoordinate.x + TILE_SPRITE_SIZE, textureCoordinate.y + TILE_SPRITE_SIZE}; //1,1
        vertex[4].texCoords = {textureCoordinate.x, textureCoordinate.y + TILE_SPRITE_SIZE}; //0, 1
        vertex[5].texCoords = {textureCoordinate.x + TILE_SPRITE_SIZE, textureCoordinate.y}; //1, 0
    }
}

Tile & Chunk::getTileAt(sf::Vector2i pos) {
    //Check if tile is inside this chunk
    if (pos.x >= 0 && pos.x < CHUNK_SIZE && pos.y >= 0 && pos.y < CHUNK_SIZE) {
        return tiles[pos.x + pos.y * CHUNK_SIZE];
    }

    //Request the tile from a neighbor
    if (pos.x < 0) {
        return m_Left->getTileAt(pos + sf::Vector2i(CHUNK_SIZE, 0));
    }
    if (pos.x >= CHUNK_SIZE) {
        return m_Right->getTileAt(pos - sf::Vector2i(CHUNK_SIZE, 0));
    }
    if (pos.y < 0) {
        return m_Up->getTileAt(pos + sf::Vector2i(0, CHUNK_SIZE));
    }
    if (pos.y >= CHUNK_SIZE) {
        return m_Down->getTileAt(pos - sf::Vector2i(0, CHUNK_SIZE));
    }

}
