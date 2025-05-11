//
// Created by rasmus on 5/8/25.
//

#include "include/Game.h"

void Game::initWindow() {
    this->p_Window = new sf::RenderWindow(sf::VideoMode({1920, 1080}), "ShrooshCraft" ,sf::Style::Titlebar | sf::Style::Close);
    this->p_Window->setFramerateLimit(240);
}

void Game::initView() {
    m_View.setSize(sf::Vector2f(1920, 1080));
    m_View.setCenter(sf::Vector2f(0, 132*16));
    p_Window->setView(m_View);
}

Game::Game() {
    this->initWindow();
    this->initView();
}

Game::~Game() {
    delete this->p_Window;
}

void Game::run() {
    while (this->p_Window->isOpen()) {
        this->update();
        this->render();
    }
}

void Game::update() {
    this->updateBaseEvents();
}

void Game::updateBaseEvents() {
    while (const std::optional event = this->p_Window->pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            this->p_Window->close();
        } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                this->p_Window->close();
            }
        }
    }
}

void Game::render() {
    this->p_Window->clear();

    //Render here
    m_World.render(p_Window);

    this->p_Window->display();
}


