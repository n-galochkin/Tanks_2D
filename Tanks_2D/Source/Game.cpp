#include "Game.h"

#include <iostream>

#include "Player.h"
#include "SFML/Window/Event.hpp"

#include "SFML/Window/Keyboard.hpp"

Game::Game()
{
    content = new ContentManager();
    field_ = new GameField(20, 20);
    player_ = new Player();
}

void Game::initialize()
{
    if (content->TryLoadFiles() == false)
    {
        exit(1);
    }

    player_->initialize();

    for (GameObject* object : objects_)
    {
        object->initialize();
    }
}

void Game::processInput(RenderWindow& window)
{

    Event event{};
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case Event::Closed:
            window.close();
            return;
        case Event::KeyPressed:
            _lastPressedKey = event.key.code;
            break;
        default:
            break;
        }
    }

    player_->processInput(_lastPressedKey);
}

void Game::update() const
{
    // TODO: static objects
    // TODO: added new object after update

    for (GameObject* object : objects_)
    {
        object->update();
    }

    // TODO: delayed delete objects
    // TODO: Pattern component
}

void Game::render(RenderWindow& window, const float deltaTime) const
{
    window.clear(Color::Black);

    // TODO: use deltaTime for smooth extrapolation
    // TODO: separate render and update move logic
    for (GameObject* object : objects_)
    {
        window.draw(object->getSprite());
    }

    window.display();
}
