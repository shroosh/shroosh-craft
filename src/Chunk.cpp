//
// Created by rasmus on 5/21/25.
//
#include "include/TextureManager.h"
#include "include/Chunk.h"

void Chunk::updateTile(Tile &tile) {
    this->setVertices(tile);
    this->setTileNeighbors(tile);
    this->updateTileTexture(tile);
}

void Chunk::setTileNeighbors(Tile &tile) {
    sf::Vector2i tilePos = tile.getPos();
    if (tilePos.y > 0) {

        if (tiles[Utils::chunkPosToIndex(tilePos.x, tilePos.y - 1)].getType() == TileType::AIR ) {
            tile.setUp(true);

        } else {
            tile.setUp(false);
        }
    } else {
        tile.setUp(false);
    }


    if (tilePos.y < CHUNK_SIZE - 1) {
        if (tiles[Utils::chunkPosToIndex(tilePos.x, tilePos.y + 1)].getType() == TileType::AIR ) {
            tile.setDown(true);
        } else {
            tile.setDown(false);
        }
    } else {
        tile.setDown(false);
    }

    if (tilePos.x < CHUNK_SIZE - 1) {
        if (tiles[Utils::chunkPosToIndex(tilePos.x + 1, tilePos.y)].getType() == TileType::AIR ) {
            tile.setRight(true);
        } else {
            tile.setRight(false);
        }
    } else {
        tile.setRight(false);
    }

    if (tilePos.x > 0) {
        if (tiles[Utils::chunkPosToIndex(tilePos.x - 1, tilePos.y)].getType() == TileType::AIR ) {
            tile.setLeft(true);
        } else {
            tile.setLeft(false);
        }
    } else {
        tile.setLeft(false);
    }
}

void Chunk::updateTileTexture(Tile &tile) {
    sf::Vector2i pos = tile.getPos();
    sf::Vertex* temp = &vertices[(pos.x + pos.y * CHUNK_SIZE) * 6];

    const sf::Vector2f texPos = textureManager.getTextureCoords(tile.getType(), tile.getUp(), tile.getRight(), tile.getDown(), tile.getLeft());

    temp[0].texCoords = sf::Vector2f(texPos.x, texPos.y); // 0, 0
    temp[1].texCoords = sf::Vector2f(texPos.x + TILE_SPRITE_SIZE, texPos.y); // 1, 0
    temp[2].texCoords = sf::Vector2f(texPos.x, texPos.y + TILE_SPRITE_SIZE); // 0, 1
    temp[3].texCoords = sf::Vector2f(texPos.x + TILE_SPRITE_SIZE, texPos.y + TILE_SPRITE_SIZE); // 1, 1
    temp[4].texCoords = sf::Vector2f(texPos.x + TILE_SPRITE_SIZE, texPos.y); // 1, 0
    temp[5].texCoords = sf::Vector2f(texPos.x, texPos.y + TILE_SPRITE_SIZE); // 0, 1
}

void Chunk::setVertices(Tile &tile) {
    sf::Vector2i pos = tile.getPos();
    sf::Vertex* temp = &vertices[(pos.x + pos.y * CHUNK_SIZE) * 6];

    temp[0].position = sf::Vector2f(pos.x * TILE_SIZE, pos.y * TILE_SIZE); // 0, 0
    temp[1].position = sf::Vector2f((pos.x + 1) * TILE_SIZE, pos.y * TILE_SIZE); // 1, 0
    temp[2].position = sf::Vector2f(pos.x * TILE_SIZE, (pos.y + 1) * TILE_SIZE); // 0, 1
    temp[3].position = sf::Vector2f((pos.x + 1) * TILE_SIZE, (pos.y + 1) * TILE_SIZE); // 1, 1
    temp[4].position = sf::Vector2f((pos.x + 1) * TILE_SIZE, pos.y * TILE_SIZE); // 1, 0
    temp[5].position = sf::Vector2f(pos.x * TILE_SIZE, (pos.y + 1) * TILE_SIZE); // 0, 1
}

void Chunk::load() {
    this->tiles.reserve(CHUNK_SIZE * CHUNK_SIZE);

    for (int i = 0; i < CHUNK_SIZE * CHUNK_SIZE; ++i) {
        Tile tile = Tile(static_cast<TileType>(this->tileData[i]), Utils::indexToChunkPos(i));
        this->tiles.emplace_back(tile);
    }

    for (int i = 0; i < CHUNK_SIZE * CHUNK_SIZE; ++i) {
        if (tiles.at(i).getType() != TileType::AIR) {
            this->updateTile(this->tiles.at(i));
        }
    }
}

void Chunk::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = texture;

    target.draw(vertices, states);
}

Chunk::Chunk(std::vector<int> &tiles, TextureManager &textureManager): tileData(tiles), textureManager(textureManager) {
    this->vertices.resize(CHUNK_SIZE*CHUNK_SIZE*6);
    this->vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    this->texture = &textureManager.getTexture();
    this->load();
}

Chunk::~Chunk() {
}
