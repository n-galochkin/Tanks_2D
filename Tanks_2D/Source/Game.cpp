#include "Game.h"
#include "Player.h"

#include "SFML/Window/Keyboard.hpp"

Game::Game()
{
    content = new ContentManager();
    field = new GameField(20, 20);
    player = new Player();
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

void Game::init()
{
    if (content->TryLoadFiles() == false)
    {
        exit(1);
    }

    player->tank = new Tank(20, 20, field);

    for (GameObject* object : objects)
    {
        object->init();
    }
}

void Game::update(float deltaTime)
{
    for (auto& object : objects)
    {
        object->update(deltaTime);
    }
}

void Game::render(sf::RenderWindow& window)
{
   
    window.draw(player->tank->sprite);
}
