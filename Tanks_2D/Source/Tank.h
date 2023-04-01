#pragma once
#include "GameObject.h"
#include "MovementDefines.h"
#include "SFML/Audio/AlResource.hpp"
#include "SFML/Graphics/Sprite.hpp"

class GameField;

class Tank : public GameObject
{
public:
    Tank(int x, int y);

    void move();
    void setMoveDirection(MoveDirection direction);
    void shoot();

    // start game object interface
    void initialize() override;

    void update() override;
    //~end game object interface

private:
    MoveDirection direction_ = None;
    float speed_{};
    bool alive_{};
    GameField* gameField{};
};
