#pragma once

class GameObject
{
public:
    int x{}, y{};

    GameObject();
    
    GameObject(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    
    void init();
    
    void update(float delta_time);
};
