//
// Created by rasmus on 5/8/25.
//

#ifndef WORLD_H
#define WORLD_H

#include "WorldGen.h"
#include "Tile.h"

class World {
private:
    std::vector<std::vector<Tile*>> map;
public:
    World();
    ~World();

    void render();
};



#endif //WORLD_H
