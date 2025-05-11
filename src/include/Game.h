//
// Created by rasmus on 5/8/25.
//

#ifndef GAME_H
#define GAME_H

#include "World.h"

class Game {
private:
    sf::RenderWindow* p_Window;
    void initWindow();

    sf::View m_View;
    void initView();

    World m_World{p_Window};

    void update();
    void updateBaseEvents();
    void render();
public:
    Game();
    ~Game();

    void run();
};



#endif //GAME_H
