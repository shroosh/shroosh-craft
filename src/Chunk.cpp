//
// Created by rasmus on 5/14/25.
//

#include "include/Chunk.h"

void Chunk::initVertices() {
    this->m_vertices.resize(CHUNK_SIZE * CHUNK_SIZE * 6);
    this->m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
}

void Chunk::setTile(int x, int y, sf::Color color) {
    float fx = static_cast<float>(x);
    float fy = static_cast<float>(y);
    sf::Vertex* tempTriangles = &m_vertices[(x + y * CHUNK_SIZE) * 6];

    tempTriangles[0].position = sf::Vector2f((CHUNK_SIZE * TILE_SIZE * static_cast<float>(position.x)) + fx * TILE_SIZE, fy * TILE_SIZE); // 0, 0
    tempTriangles[1].position = sf::Vector2f((CHUNK_SIZE * TILE_SIZE * static_cast<float>(position.x)) +(fx + 1) * TILE_SIZE, fy * TILE_SIZE); // 1, 0
    tempTriangles[2].position = sf::Vector2f((CHUNK_SIZE * TILE_SIZE * static_cast<float>(position.x)) +fx * TILE_SIZE, (fy + 1) * TILE_SIZE); // 0, 1
    tempTriangles[3].position = sf::Vector2f((CHUNK_SIZE * TILE_SIZE * static_cast<float>(position.x)) +(fx + 1) * TILE_SIZE, (fy + 1) * TILE_SIZE); // 1, 1
    tempTriangles[4].position = sf::Vector2f((CHUNK_SIZE * TILE_SIZE * static_cast<float>(position.x)) +(fx + 1) * TILE_SIZE, fy * TILE_SIZE); // 1, 0
    tempTriangles[5].position = sf::Vector2f((CHUNK_SIZE * TILE_SIZE * static_cast<float>(position.x)) +fx * TILE_SIZE, (fy + 1) * TILE_SIZE); // 0, 1

    // tempTriangles[0].texCoords = sf::Vector2f(0, 0); // 0, 0
    // tempTriangles[1].texCoords = sf::Vector2f(16, 0); // 1, 0
    // tempTriangles[2].texCoords = sf::Vector2f(0, 16); // 0, 1
    // tempTriangles[3].texCoords = sf::Vector2f(16, 16); // 1, 1
    // tempTriangles[4].texCoords = sf::Vector2f(16, 0); // 1, 0
    // tempTriangles[5].texCoords = sf::Vector2f(0, 16); // 0, 1

    tempTriangles[0].color = color;
    tempTriangles[1].color = color;
    tempTriangles[2].color = color;
    tempTriangles[3].color = color;
    tempTriangles[4].color = color;
    tempTriangles[5].color = color;
}

void Chunk::updateTileTextures() {
    for (int x = 0; x < CHUNK_SIZE; ++x) {
        for (int y = 0; y < CHUNK_SIZE; ++y) {
            if (this->tiles[x][y] == TileType::AIR) {
                break;
            }


        }
    }
}

void Chunk::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    //states.texture = p_texture;
    target.draw(m_vertices, states);
}

void Chunk::generateTileData(std::array<int, CHUNK_SIZE> heights) {
    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int y = heights[x]; y < CHUNK_SIZE; y++) {

            if (y == heights[x]) {
                this->setTile(x, y, sf::Color::Green);
                this->tiles[x][y] = TileType::GRASS;
            } else {
                this->tiles[x][y] = TileType::DIRT;
                this->setTile(x, y, sf::Color::White);
            }
        }
    }
}

Chunk::Chunk(sf::Vector2i chunkPos, std::array<int, CHUNK_SIZE> heights) {
    this->position = chunkPos;
    this->initVertices();
    this->generateTileData(heights);

    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int y = 0; y < CHUNK_SIZE; y++) {
            std::cout << static_cast<int>(this->tiles[y][x]) << " ";
        }
        std::cout << std::endl;
    }
}

Chunk::~Chunk() {
}
