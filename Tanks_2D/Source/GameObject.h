#pragma once
#include "SFML/Graphics/Sprite.hpp"

using namespace sf;

class GameObject
{
public:
    GameObject();
    GameObject(int x, int y);
    virtual ~GameObject();
    
    virtual void initialize();
    
    virtual void update();

    Sprite& getSprite();

    virtual void move(const Vector2f& offset);

private:
    Sprite sprite_;

    Vector2f position_;
};
