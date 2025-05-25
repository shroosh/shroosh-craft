//
// Created by rasmus on 5/21/25.
//

#include "include/Utils.h"

std::size_t Utils::Vector2iHash::operator()(const sf::Vector2i &v) const {
    {
        // int result = v.x + v.y * 40;
        // return std::hash<int>()(result);

        std::size_t hx = std::hash<int>{}(v.x);
        std::size_t hy = std::hash<int>{}(v.y);
        return hx ^ (hy << 1);
    }
}

int Utils::chunkPosToIndex(int x, int y) {
    return x * 40 + y;
}

sf::Vector2i Utils::indexToChunkPos(int index) {
    sf::Vector2i chunkPos;
    chunkPos.y = index % 40;
    chunkPos.x = index / 40;
    return chunkPos;
}

__uint8_t Utils::neighboursToBitMask(bool up, bool right, bool down, bool left) {
    __uint8_t result = 0;
    if (up)
        result |= (1 << 0);
    if (right)
        result |= (1 << 1);
    if (down)
        result |= (1 << 2);
    if (left)
        result |= (1 << 3);

    return result;
}
