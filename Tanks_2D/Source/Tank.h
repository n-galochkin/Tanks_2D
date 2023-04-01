#pragma once
#include "GameObject.h"
#include "SFML/Audio/AlResource.hpp"
#include "SFML/Graphics/Sprite.hpp"

class GameField;

class Tank : public GameObject
{
public:
    Tank(int x, int y, GameField* gameField);
    Tank(int x, int y);

    void move();
    void turn(int new_direction);
    void shoot();
    void update(float delta_time);

private:
    int direction{};
    int speed{};
    bool alive{};
    GameField* gameField{};
};
