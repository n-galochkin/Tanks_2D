
#include "libs/include/SFML/Graphics/RenderWindow.hpp"
#include "libs/include/SFML/Window/VideoMode.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Window/Event.hpp"

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tanks");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}
