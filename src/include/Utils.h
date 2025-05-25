//
// Created by rasmus on 5/21/25.
//

#ifndef UTILS_H
#define UTILS_H

#include <cstddef>
#include <functional>
#include <bits/types.h>
#include <SFML/System/Vector2.hpp>



namespace Utils {
    struct Vector2iHash {
        std::size_t operator()(const sf::Vector2i &v) const;
    };

    int chunkPosToIndex(int x, int y);

    sf::Vector2i indexToChunkPos(int index);

    __uint8_t neighboursToBitMask(bool up, bool right, bool down, bool left);
}



#endif //UTILS_H
