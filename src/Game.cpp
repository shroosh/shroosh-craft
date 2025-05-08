//
// Created by rasmus on 5/8/25.
//

#include "include/Game.h"

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode({1920, 1080}), "ShrooshCraft" ,sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(240);
}

void Game::initView() {
}

Game::Game() {
    this->initWindow();
}

Game::~Game() {
    delete this->window;
}

void Game::run() {
    while (this->window->isOpen()) {
        this->update();
        this->render();
    }
}

void Game::update() {
    this->updateBaseEvents();
}

void Game::updateBaseEvents() {
    while (const std::optional event = window->pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            this->window->close();
        } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                this->window->close();
            }
        }
    }
}

void Game::render() {
    this->window->clear();

    //Render here

    this->window->display();
}


