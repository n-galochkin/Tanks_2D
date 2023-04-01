
#include "Player.h"

#include <iostream>

#include "MovementDefines.h"
#include "SFML/Window/Keyboard.hpp"

Player::Player()
= default;

void Player::initialize()
{
    tank = new Tank(20, 20);
}

void Player::processInput()
{
    if(tank == nullptr)
    {
        return;
    }

    MoveDirection moveDirection = None;

    // TODO: set only for last pressed key
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        std::cout << "Press Up" << std::endl;
        moveDirection = Up;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        std::cout << "Press Right" << std::endl;
        moveDirection = Right;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        std::cout << "Press Down" << std::endl;
        moveDirection = Down;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        std::cout << "Press Left" << std::endl;
        moveDirection = Left;
    }

    tank->setMoveDirection(moveDirection);
    
    if (Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        tank->shoot();
    }
}
