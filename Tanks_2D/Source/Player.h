#pragma once

#include "Tank.h"

class Player
{
public:
    Tank* tank{};

    Player(int x, int y) {}
    Player() = default;
};
