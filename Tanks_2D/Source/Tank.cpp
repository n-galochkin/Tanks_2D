#include "Tank.h"

#include <iostream>

#include "GameField.h"
#include "Bullet.h"
#include "Game.h"
#include "MovementDefines.h"

Tank::Tank(int x, int y) : GameObject(x, y)
{
    this->speed_ = 1.f;
    this->alive_ = true;   
}

void Tank::initialize()
{
    GameObject::initialize();

    getSprite().setTexture(Game::instance().get_content_manager().T_LightTank);
    getSprite().setScale(0.2f, 0.2f);
}

void Tank::update()
{
    GameObject::update();
    
    move();
}

void Tank::move()
{
    if(direction_ == None)
    {
        return;
    }
    
    Vector2f offset;
    switch (direction_)
    {
    case Up:    offset.y -= speed_; break;
    case Right: offset.x += speed_; break;
    case Down:  offset.y += speed_; break;
    case Left:  offset.x -= speed_; break;
    default: ;
    }

    std::cout << "Tank move: (" << offset.x << ", " << offset.y << ")" << std::endl;
    
    GameObject::move(offset);
}

void Tank::setMoveDirection(MoveDirection direction)
{
    direction_ = direction;
}

void Tank::shoot()
{
    int bullet_x = 0;
    int bullet_y = 0;
    switch (direction_)
    {
    case Up:    bullet_y -= 1; break;
    case Right: bullet_x += 1; break;
    case Down:  bullet_y += 1; break;
    case Left:  bullet_x -= 1; break;
    default: ;
    }
    
    Bullet bullet(bullet_x, bullet_y, direction_);
    gameField->bullets.push_back(bullet);
}
