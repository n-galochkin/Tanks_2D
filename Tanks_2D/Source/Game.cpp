#include "Game.h"
#include "Player.h"

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

void Game::processInput() const
{
    player_->processInput();
}

void Game::update(float deltaTime) const
{
    for (GameObject* object : objects_)
    {
        object->update(deltaTime);
    }
}

void Game::render(sf::RenderWindow& window) const
{
    for (GameObject* object : objects_)
    {
        window.draw(object->getSprite());
    }
}
