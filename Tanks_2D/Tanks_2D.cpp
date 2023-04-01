#include <iostream>

#include "libs/include/SFML/Graphics/RenderWindow.hpp"
#include "libs/include/SFML/Window/VideoMode.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Event.hpp"

#include "Source/Game.h"

const float MS_PER_UPDATE = 1.f / 60.f;

void handleWindowCloseEvent(RenderWindow& window)
{
    Event event{};
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            window.close();
        }
    }
}

int main(int argc, char* argv[])
{
    Game& game = Game::instance();
    game.initialize();

    RenderWindow window(VideoMode(1000, 1000), "Tanks");

    Clock clock;
    float timeLag = 0.0f;

    // Game loop
    // TODO: What about CS:GO2 tickrate?
    while (window.isOpen())
    {
        handleWindowCloseEvent(window);

        game.processInput();

        timeLag += clock.restart().asSeconds();

        while (timeLag >= MS_PER_UPDATE)
        {
            game.update();
            timeLag -= MS_PER_UPDATE;
        }

        game.render(window, timeLag / MS_PER_UPDATE);
    }

    return 0;
}
