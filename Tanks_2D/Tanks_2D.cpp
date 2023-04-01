#include <iostream>

#include "libs/include/SFML/Graphics/RenderWindow.hpp"
#include "libs/include/SFML/Window/VideoMode.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Event.hpp"

#include "Source/Game.h"

int main(int argc, char* argv[])
{
    Game& game = Game::instance();
    game.initialize();

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Tanks");
    sf::Clock clock;

    float deltaTime;


    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        game.processInput();
        game.update(deltaTime);

        window.clear(sf::Color::Black);
        game.render(window);
        window.display();
    }

    return 0;
}
