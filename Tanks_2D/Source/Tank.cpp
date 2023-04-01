#include "Tank.h"

#include "GameField.h"
#include "Bullet.h"
#include "Game.h"

Tank::Tank(int x, int y, GameField* gameField): GameObject(), gameField(gameField)
{
    this->x = x;
    this->y = y;
    this->direction = 0;
    this->speed = 1;
    this->alive = true;

    sprite.setTexture(Game::instance().get_content_manager().T_LightTank);
}

Tank::Tank(int x, int y) : GameObject()
{
    this->x = x;
    this->y = y;    
}

void Tank::move()
{
    switch (direction)
    {
    case 0: y -= speed;
        break;
    case 1: x += speed;
        break;
    case 2: y += speed;
        break;
    case 3: x -= speed;
        break;
    default: ;
    }
}

void Tank::turn(int new_direction)
{
    direction = new_direction % 4;
}

void Tank::shoot()
{
    int bullet_x = x;
    int bullet_y = y;
    switch (direction)
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
    Bullet bullet(bullet_x, bullet_y, direction);
    gameField->bullets.push_back(bullet);
}

void Tank::update(float delta_time)
{
    
}
