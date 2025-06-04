//
// Created by rasmus on 5/8/25.
//

#ifndef WORLDGEN_H
#define WORLDGEN_H

#include <SFML/Graphics.hpp>
#include <noise/noise.h>
#include "Tile.h"
#include "Config.h"

class WorldGen {
private:
    noise::module::Perlin singlePerlin;
    noise::module::Perlin doublePerlin;
    void initPerlin();
public:
    WorldGen();
    ~WorldGen();

    std::vector<Tile> generate(sf::Vector2i pos);
};



#endif //WORLDGEN_H
