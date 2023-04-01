#pragma once

#include "SFML/Graphics/Texture.hpp"

class ContentManager
{
public:
    ContentManager() = default;
    
    sf::Texture T_LightTank;

    bool TryLoadFiles();
};
