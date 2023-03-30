#include "Game.h"

#include "Bullet.h"
#include "SFML/Window/Keyboard.hpp"

void Game::handleInput()
{
    // обработка пользовательского ввода
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        gameField.player.tank.turn(0); // поворот направо
        gameField.player.tank.move(); // движение в направлении танка
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        gameField.player.tank.turn(1); // поворот направо
        gameField.player.tank.move(); // движение в направлении танка
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        gameField.player.tank.turn(2); // поворот направо
        gameField.player.tank.move(); // движение в направлении танка
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        gameField.player.tank.turn(3); // поворот направо
        gameField.player.tank.move(); // движение в направлении танка
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        gameField.player.tank.shoot(); // выстрел из танка
    }
}

void Game::update(float deltaTime)
{
    // обновление игры
    for (auto& tank : gameField.enemies) {
        tank.update(deltaTime);
    }
    for (auto& bullet : gameField.bullets) {
        bullet.update(deltaTime);
    }
}

void Game::render(sf::RenderWindow& window)
{
    // рендер игры
    gameField.Render(window);
}
