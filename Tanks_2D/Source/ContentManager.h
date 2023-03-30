#pragma once

#include "SFML/Graphics/Texture.hpp"

class ContentManager
{
public:
    sf::Texture T_LightTank;

    bool TryLoadFiles();
};
