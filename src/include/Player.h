//
// Created by rasmus on 5/18/25.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
private:
    void updateMovement();
public:
    Player();
    void update();
};



#endif //PLAYER_H
