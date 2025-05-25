//
// Created by rasmus on 5/8/25.
//

#ifndef WORLDGEN_H
#define WORLDGEN_H

#include <SFML/Graphics.hpp>
#include <noise/noise.h>

class WorldGen {
private:
    noise::module::Perlin singlePerlin;
    noise::module::Perlin doublePerlin;
    void initPerlin();
public:
    WorldGen();
    ~WorldGen();

    std::vector<int> generateChunk(sf::Vector2i pos);
};



#endif //WORLDGEN_H
