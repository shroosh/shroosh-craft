//
// Created by rasmus on 5/8/25.
//

#include "include/Game.h"

void Game::initWindow() {
    this->p_Window = new sf::RenderWindow(sf::VideoMode({1920, 1080}), "ShrooshCraft" ,sf::Style::Titlebar | sf::Style::Close);
    this->p_Window->setFramerateLimit(240);

    view.setSize(sf::Vector2f(1920, 1080));
    view.setCenter({0,0});
    p_Window->setView(view);
}

void Game::initView() {
}

Game::Game() {
    this->initWindow();
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
    this->updateKeyboardEvents();
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

void Game::updateKeyboardEvents() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        this->view.move(sf::Vector2f(0.f, -10.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        this->view.move(sf::Vector2f(-10.f, 0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        this->view.move(sf::Vector2f(0.f, 10.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        this->view.move(sf::Vector2f(10.f, 0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        this->view.zoom(1.005);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
        this->view.zoom(0.995);
    }
    this->p_Window->setView(this->view);
}

void Game::render() {
    this->p_Window->clear();

    //Render here
    m_World.render(*p_Window);

    this->p_Window->display();
}


