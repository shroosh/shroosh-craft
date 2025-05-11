//
// Created by rasmus on 5/8/25.
//

#ifndef WORLD_H
#define WORLD_H

#include "Tile.h"

class World {
private:
    int m_worldWidth;
    int m_worldHeight;
    int m_topHeight;
    int m_bottomHeight;
    float m_tileSize;
    void initVariables();

    int generateRandomHeight(int lastHeight);

    std::vector<std::vector<std::vector<Tile*>>> m_Map;
    void generateBaseLayer();

public:
    World(sf::RenderTarget* window);
    ~World();

    void render(sf::RenderTarget* m_renderTarget);
};



#endif //WORLD_H
