#pragma once

#include <map>
#include <queue>
#include <set>
#include <unordered_set>

#include "Tank.h"
#include "SFML/Window/Keyboard.hpp"

class Player
{
public:
    Tank* tank{};

    Player() = default;
    Player(int x, int y) {}

    void initialize();
    void processInput(Keyboard::Key lastKeyPressed);

private:
    std::map<Keyboard::Key, MoveDirection> _moveInputBindings = {
        {Keyboard::Up, Up},
        {Keyboard::Right, Right},
        {Keyboard::Down, Down},
        {Keyboard::Left, Left}
    };

    Keyboard::Key _lastKeyPressed = Keyboard::Unknown;
    std::unordered_set<Keyboard::Key> _pressedMoveKeys{};
};
