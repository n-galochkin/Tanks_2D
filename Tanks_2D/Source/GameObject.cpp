#include "GameObject.h"

#include <iostream>

#include "Game.h"

GameObject::GameObject()
{
    Game::instance().add_object(this);
}

GameObject::GameObject(int x, int y) : GameObject()
{
    position_.x = x;
    position_.y = y;
}

GameObject::~GameObject()
= default;

void GameObject::initialize()
{
    
}

void GameObject::update(float delta_time)
{
    
}

Sprite& GameObject::getSprite()
{
    return sprite_;
}

void GameObject::move(const Vector2f& offset)
{
    position_ += offset;
    
    sprite_.setPosition(position_);
    
    std::cout << "Object sprite new position: (" << position_.x << ", " << position_.y << ")" << std::endl;
}