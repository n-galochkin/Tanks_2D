#pragma once

#include <vector>

#include "Bullet.h"
#include "Player.h"
#include "SFML/Graphics/RenderWindow.hpp"

using namespace std;


class GameField {
public:
    Player player;
    vector<Tank> enemies;
    vector<Bullet> bullets;

    GameField(int player_x, int player_y) : player(player_x, player_y) {}
    void Render(const sf::RenderWindow& Window);
};
