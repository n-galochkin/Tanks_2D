
#include "Player.h"

#include <iostream>

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
    
    if (Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        std::cout << "Press Up" << std::endl;
        tank->turn(0);
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        std::cout << "Press Right" << std::endl;
        tank->turn(1);
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        std::cout << "Press Down" << std::endl;
        tank->turn(2);
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        std::cout << "Press Left" << std::endl;
        tank->turn(3);
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        tank->shoot();
    }
}
