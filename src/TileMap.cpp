//
// Created by rasmus on 5/12/25.
//

#include "include/TileMap.h"

#include <iostream>
#include <map>

void TileMap::initVertices(int mapData[40][40]) {
    this->m_vertices.resize(40*40*6);
    this->m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);

    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int y = 0; y < CHUNK_SIZE; y++) {
            if (mapData[x][y] == 0) {
                break;
            }
            sf::Vertex* tempTriangles = &m_vertices[(x + y * CHUNK_SIZE) * 6];

            tempTriangles[0].position = sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE); // 0, 0
            tempTriangles[1].position = sf::Vector2f((x + 1) * TILE_SIZE, y * TILE_SIZE); // 1, 0
            tempTriangles[2].position = sf::Vector2f(x * TILE_SIZE, (y + 1) * TILE_SIZE); // 0, 1
            tempTriangles[3].position = sf::Vector2f((x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE); // 1, 1
            tempTriangles[4].position = sf::Vector2f((x + 1) * TILE_SIZE, y * TILE_SIZE); // 1, 0
            tempTriangles[5].position = sf::Vector2f(x * TILE_SIZE, (y + 1) * TILE_SIZE); // 0, 1

            tempTriangles[0].texCoords = sf::Vector2f(0, 0); // 0, 0
            tempTriangles[1].texCoords = sf::Vector2f(16, 0); // 1, 0
            tempTriangles[2].texCoords = sf::Vector2f(0, 16); // 0, 1
            tempTriangles[3].texCoords = sf::Vector2f(16, 16); // 1, 1
            tempTriangles[4].texCoords = sf::Vector2f(16, 0); // 1, 0
            tempTriangles[5].texCoords = sf::Vector2f(0, 16); // 0, 1

            // tempTriangles[0].color = sf::Color::Blue;
            // tempTriangles[1].color = sf::Color::White;
            // tempTriangles[2].color = sf::Color::White;
            // tempTriangles[3].color = sf::Color::White;
            // tempTriangles[4].color = sf::Color::White;
            // tempTriangles[5].color = sf::Color::White;

        }
    }
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = p_texture;
    target.draw(m_vertices, states);
}

TileMap::TileMap(int mapData[CHUNK_SIZE][CHUNK_SIZE], sf::Texture *p_texture) {
    this->initVertices(mapData);
    this->p_texture = p_texture;

    //EXTRA
    // this->m_vertices.resize(40*40*6);
    // this->m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    // this->m_vertices[0].position = sf::Vector2f(0, 0);
    // this->m_vertices[1].position = sf::Vector2f(300.f, 0);
    // this->m_vertices[2].position = sf::Vector2f(0, 300.f);
    //
    // this->m_vertices[3].position = sf::Vector2f(300.f, 0);
    // this->m_vertices[4].position = sf::Vector2f(600.f, 0);
    // this->m_vertices[5].position = sf::Vector2f(300.f, 300.f);
    //
    // this->m_vertices[0].texCoords = sf::Vector2f(0, 0);
    // this->m_vertices[1].texCoords = sf::Vector2f(16, 0);
    // this->m_vertices[2].texCoords = sf::Vector2f(0, 16);
    //
    // this->m_vertices[3].texCoords = sf::Vector2f(0, 0);
    // this->m_vertices[4].texCoords = sf::Vector2f(16, 0);
    // this->m_vertices[5].texCoords = sf::Vector2f(0, 16);
}

TileMap::~TileMap() {
}
