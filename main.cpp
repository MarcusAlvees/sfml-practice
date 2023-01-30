#include <SFML/Graphics.hpp>
#include "Headers/Player.hpp"
#include "Headers/DrawMap.hpp"

sf::RenderWindow window(sf::VideoMode(1280, 736), "Game!");
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
        //mapTiles.setUpTiles();
        p.update(window);

        window.clear(sf::Color(102, 135, 255, 255));
        mapTiles.drawTiles(window, p.camPos);
        p.render(window);
        window.display();
    }

    return 0;
}
