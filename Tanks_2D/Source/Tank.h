#pragma once

class GameField;

class Tank
{
public:
    Tank(int x, int y, GameField* gameField);
    Tank(int x, int y);

    void move();
    void turn(int new_direction);
    void shoot();
    void update(float delta_time);

private:
    int x, y;
    int direction{};
    int speed{};
    bool alive{};
    GameField* gameField{};
};
