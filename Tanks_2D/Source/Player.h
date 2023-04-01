#pragma once

#include "Tank.h"

class Player
{
public:
    Tank* tank{};

    Player();
    Player(int x, int y) {}

    void initialize();
    void processInput();
};
