#pragma once

#include "GameField.h"
#include "SFML/Graphics/RenderWindow.hpp"

class Game {
public:
    Game() : gameField(20, 20) {} // инициализация игрового поля

    void handleInput();

    void update(float deltaTime);

    void render(sf::RenderWindow& window);

private:
    GameField gameField; // игровое поле
};
