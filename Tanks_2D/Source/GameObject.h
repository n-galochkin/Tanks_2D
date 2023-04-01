#pragma once
#include "SFML/Graphics/Sprite.hpp"

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
    
    void initialize();
    
    void update(float delta_time);

    sf::Sprite& getSprite()
    {
        return sprite_;
    }

protected:
    sf::Sprite sprite_;
};
