#include <SFML/Graphics.hpp>
#include "Headers/Player.hpp"

sf::RenderWindow window(sf::VideoMode(1280, 720), "Game!");
float movementSpeed = 2.f;
sf::RectangleShape shape;
Player p;

int main()
{
    window.setFramerateLimit(120);

    //Game Loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        p.update(window);

        window.clear();
        p.render(window);
        window.display();
    }

    return 0;
}
