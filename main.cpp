#include <SFML/Graphics.hpp>
#include "Headers/Player.hpp"
#include "Headers/DrawMap.hpp"

sf::RenderWindow window(sf::VideoMode(1280, 720), "Game!");
float movementSpeed = 2.f;
sf::RectangleShape shape;
Player p;
DrawMap mapTiles = DrawMap();

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
        mapTiles.drawTiles(window);
        p.render(window);
        window.display();
    }

    return 0;
}
