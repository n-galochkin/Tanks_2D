#include "GameObject.h"

#include "Game.h"

GameObject::GameObject()
{
    Game::instance().add_object(this);
}

void GameObject::initialize()
{
    
}

void GameObject::update(float delta_time)
{
    
}
