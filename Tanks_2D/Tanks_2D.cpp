
#include <iostream>

#include "libs/include/SFML/Graphics/RenderWindow.hpp"
#include "libs/include/SFML/Window/VideoMode.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Event.hpp"
#include "Source/ContentManager.h"
#include "Source/Game.h"

int main(int argc, char* argv[])
{
    Game game;
    
    ContentManager contentManager;
    if(contentManager.TryLoadFiles() == false)
    {
        return 1;
    }
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tanks");
    sf::Clock clock;
    
    float deltaTime;
    
    
    sf::Sprite tank1(contentManager.T_LightTank);
    
    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        game.handleInput();
        game.update(deltaTime);

        window.clear(sf::Color::Black);        
        window.draw(tank1);
        game.render(window);
        window.display();
    }

    return 0;
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);
    //
    // while (window.isOpen())
    // {
    //     sf::Event event{};
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }
    //
    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }
    // return 0;
}
