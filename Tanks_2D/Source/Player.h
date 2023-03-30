#pragma once

#include "Tank.h"

class Player {
public:
    Tank tank; // танк игрока

    Player(int x, int y) : tank(x, y) {}
};
