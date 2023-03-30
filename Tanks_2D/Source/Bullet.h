#pragma once

class Bullet
{
public:
    int x, y;
    int direction;
    int speed;

    Bullet(int x, int y, int direction)
    {
        this->x = x;
        this->y = y;
        this->direction = direction;
        this->speed = 3;
    }

    void move()
    {
        switch (direction)
        {
        case 0: y -= speed;
            break; // движение вверх
        case 1: x += speed;
            break; // движение вправо
        case 2: y += speed;
            break; // движение вниз
        case 3: x -= speed;
            break; // движение влево
        default: ;
        }
    }

    void update(float delta_time);
};
