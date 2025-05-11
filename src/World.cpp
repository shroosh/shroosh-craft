//
// Created by rasmus on 5/8/25.
//

#include "include/World.h"

void World::initVariables() {
    this->m_worldWidth = 800;
    this->m_worldHeight = 400;
    this->m_topHeight = this->m_worldHeight * 1 / 2;
    this->m_bottomHeight = this->m_worldHeight * 1 / 4;
    this->m_tileSize = 16.f;
    this->m_Map.resize(m_worldWidth, std::vector<std::vector<Tile*>>());
    for (int i = 0; i < m_worldWidth; i++) {
        this->m_Map[i].resize(m_worldHeight, std::vector<Tile*>());
    }
    for (int x = 0; x < m_worldWidth; x++) {
        for (int y = 0; y < m_worldHeight; y++) {
            this->m_Map[x][y].push_back(new Tile(TileType::AIR));
        }
    }
}

int World::generateRandomHeight(int lastHeight) {
    if (lastHeight == this->m_topHeight) {
        return lastHeight + rand() % 2;
    }
    if (lastHeight == this->m_topHeight) {
        return lastHeight - rand() % 2;
    }
    return lastHeight + rand() % 3 - 1;
}

void World::generateBaseLayer() {
    int height;
    for (int x = 0; x < this->m_worldWidth; ++x) {
        if (x == 0) {
            height = rand() % (this->m_bottomHeight + 1) + this->m_topHeight - this->m_bottomHeight;
        } else {
            height = this->generateRandomHeight(height);
        }

        this->m_Map[x][height].push_back(new Tile(TileType::GRASS, m_tileSize, static_cast<float>(x), static_cast<float>(height)));
        std::cout << static_cast<float>(x) << std::endl;

        for (int y = height + 1; y < m_worldHeight; ++y) {
            this->m_Map[x][y].push_back(new Tile(TileType::DIRT, m_tileSize, static_cast<float>(x), static_cast<float>(y)));
        }
    }

    // for (int x = 0; x < m_worldWidth; x++) {
    //     this->m_Map[x][0].push_back(new Tile(TileType::GRASS, m_tileSize, static_cast<float>(x), static_cast<float>(0)));
    // }
    // for (int x = 0; x < m_worldWidth; x++) {
    //     for (int y = 1; y < m_worldHeight; y++) {
    //         this->m_Map[x][y].push_back(new Tile(TileType::DIRT, m_tileSize, static_cast<float>(x), static_cast<float>(y)));
    //     }
    // }
}

World::World(sf::RenderTarget* window) {
    this->initVariables();
    this->generateBaseLayer();
    // for (int i = 0; i < this->m_worldWidth; i++) {
    //     for (int j = 0; j < this->m_worldHeight; j++) {
    //         m_Map[i][j].push_back(new Tile(TileType::GRASS, m_tileSize, static_cast<float>(i), static_cast<float>(j)));
    //     }
    // }
}

World::~World() {
}

void World::render(sf::RenderTarget* m_renderTarget) {
    for (int x = 0; x < this->m_worldWidth; ++x) {
        for (int y = 0; y < this->m_worldHeight; ++y) {
            // this->m_Map[x][y].back()->render(m_renderTarget);
            m_Map[x][y].back()->render(m_renderTarget);
        }
    }
}
