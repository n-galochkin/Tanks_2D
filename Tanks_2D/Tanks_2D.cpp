
#include "libs/include/SFML/Graphics/RenderWindow.hpp"
#include "libs/include/SFML/Window/VideoMode.hpp"
#include "SFML/Window/Event.hpp"

#include "Source/Game.h"

const float MS_PER_UPDATE = 1.f / 60.f;

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
        game.processInput(window);

        timeLag += clock.restart().asSeconds();

        // Fixed time for update game logic.
        // If render time is too long, we got timeLag > MS_PER_UPDATE
        // and we can update game logic several times in one frame, to catch up with real time.
        // But we must control that game update time is less then MS_PER_UPDATE.
        while (timeLag >= MS_PER_UPDATE)
        {
            game.update();
            timeLag -= MS_PER_UPDATE;
        }

        game.render(window, timeLag / MS_PER_UPDATE);
    }

    return 0;
}
