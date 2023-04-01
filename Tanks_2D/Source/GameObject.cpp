#include "GameObject.h"

#include "Game.h"

GameObject::GameObject()
{
    Game::instance().add_object(this);
}

void GameObject::init()
{
    
}

void GameObject::update(float delta_time)
{
    
}
