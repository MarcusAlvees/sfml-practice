#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameTile.hpp"
#include "Global.hpp"

class DrawMap
{
    sf::Vector2i playerPos;
    void initialState();
    void setUpTiles();

public:
    std::vector<GameTile*> row;
    int gridLength;
    DrawMap();
    void drawTiles(sf::RenderWindow& window);
};
