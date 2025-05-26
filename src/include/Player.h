//
// Created by rasmus on 5/25/25.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>


class Player {
private:
    sf::RectangleShape player;
public:
    Player();
    ~Player();
    sf::FloatRect getBounds();
};



#endif //PLAYER_H
