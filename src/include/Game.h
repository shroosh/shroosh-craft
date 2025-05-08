//
// Created by rasmus on 5/8/25.
//

#ifndef GAME_H
#define GAME_H

#include "World.h"

class Game {
private:
    sf::RenderWindow* window;
    void initWindow();

    sf::View view;
    void initView();
public:
    Game();
    ~Game();

    void run();
    void update();
    void updateBaseEvents();
    void render();
};



#endif //GAME_H
