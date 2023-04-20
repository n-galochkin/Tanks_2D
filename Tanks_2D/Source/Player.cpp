#include "Player.h"

#include <iostream>
#include <ranges>
#include <set>
#include <string>

#include "MovementDefines.h"
#include "SFML/Window/Keyboard.hpp"

void Player::initialize()
{
    tank = new Tank(20, 20);
}

void Player::processInput(Keyboard::Key lastKeyPressed)
{
    if (tank == nullptr)
    {
        return;
    }

    for (const auto key : _moveInputBindings | std::views::keys)
    {
        if (Keyboard::isKeyPressed(key))
        {
            if (_pressedMoveKeys.contains(key) == false)
            {
                _pressedMoveKeys.insert(key);
            }
        }
        else
        {
            _pressedMoveKeys.erase(key);
        }
    }

    MoveDirection moveDirection = None;
    
    if (_pressedMoveKeys.empty() == false)
    {
        const Keyboard::Key lastKey = *(--_pressedMoveKeys.end());
        moveDirection = _moveInputBindings[lastKey];
    }
    
    tank->setMoveDirection(moveDirection);

    if (Keyboard::isKeyPressed(Keyboard::Space))
    {
        tank->shoot();
    }
}
