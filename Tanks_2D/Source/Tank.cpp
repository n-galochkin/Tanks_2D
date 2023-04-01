#include "Tank.h"

#include <iostream>

#include "GameField.h"
#include "Bullet.h"
#include "Game.h"

Tank::Tank(int x, int y) : GameObject(x, y)
{
    this->direction_ = -1;
    this->speed_ = 1;
    this->alive_ = true;   
}

void Tank::initialize()
{
    GameObject::initialize();

    getSprite().setTexture(Game::instance().get_content_manager().T_LightTank);
    getSprite().setScale(0.2f, 0.2f);
}

void Tank::update(float delta_time)
{
    GameObject::update(delta_time);
    
    move();
}

void Tank::move()
{
    if(direction_ == -1)
    {
        return;
    }
    
    Vector2f offset;
    
    switch (direction_)
    {
    case 0: offset.y -= speed_;
        break;
    case 1: offset.x += speed_;
        break;
    case 2: offset.y += speed_;
        break;
    case 3: offset.x -= speed_;
        break;
    default: ;
    }
    
    direction_ = -1;

    std::cout << "Tank move: (" << offset.x << ", " << offset.y << ")" << std::endl;
    
    GameObject::move(offset);
}

void Tank::turn(int new_direction)
{
    direction_ = new_direction % 4;
}

void Tank::shoot()
{
    int bullet_x = 0;
    int bullet_y = 0;
    switch (direction_)
    {
    case 0: bullet_y -= 1;
        break;
    case 1: bullet_x += 1;
        break;
    case 2: bullet_y += 1;
        break;
    case 3: bullet_x -= 1;
        break;
    default: ;
    }
    Bullet bullet(bullet_x, bullet_y, direction_);
    gameField->bullets.push_back(bullet);
}
