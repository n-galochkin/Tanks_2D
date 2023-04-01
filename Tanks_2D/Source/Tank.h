#pragma once
#include "GameObject.h"
#include "SFML/Audio/AlResource.hpp"
#include "SFML/Graphics/Sprite.hpp"

class GameField;

class Tank : public GameObject
{
public:
    Tank(int x, int y);

    void move();
    void turn(int new_direction);
    void shoot();

    // start game object interface
    void initialize() override;

    void update(float delta_time) override;
    //~end game object interface

private:
    int direction_{};
    int speed_{};
    bool alive_{};
    GameField* gameField{};
};
