#include "Game.h"
#include "Player.h"

#include "SFML/Window/Keyboard.hpp"

Game::Game()
{
    content = new ContentManager();
    field_ = new GameField(20, 20);
    player_ = new Player();
}

void Game::handleInput()
{
    // обработка пользовательского ввода
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    // {
    //     field.player.tank.turn(0); // поворот направо
    //     field.player.tank.move(); // движение в направлении танка
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    // {
    //     field.player.tank.turn(1); // поворот направо
    //     field.player.tank.move(); // движение в направлении танка
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    // {
    //     field.player.tank.turn(2); // поворот направо
    //     field.player.tank.move(); // движение в направлении танка
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    // {
    //     field.player.tank.turn(3); // поворот направо
    //     field.player.tank.move(); // движение в направлении танка
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    // {
    //     field.player.tank.shoot(); // выстрел из танка
    // }
}

void Game::initialize()
{
    if (content->TryLoadFiles() == false)
    {
        exit(1);
    }

    player_->tank = new Tank(20, 20, field_);

    for (GameObject* object : objects_)
    {
        object->initialize();
    }
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
