//
// Created by rasmus on 5/18/25.
//

#ifndef VECTOR2IHASH_H
#define VECTOR2IHASH_H
#include <cstddef>
#include <functional>
#include <SFML/System/Vector2.hpp>
#include "Chunk.h"

struct Vector2iHash {
    std::size_t operator()(const sf::Vector2i &v) const {
        int result = v.x + v.y * CHUNK_SIZE;
        return std::hash<int>()(result);
    }
};

#endif //VECTOR2IHASH_H
