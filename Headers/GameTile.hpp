#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class GameTile
{

public:
    bool collisions_on;
    bool needToDraw;
    sf::Vector2f pos;
    sf::Texture texture;
    sf::Sprite spr;
    GameTile(std::string textureName, float x, float y, bool collisions, bool drawNeeded);
    bool setUpSprite(std::string textureName);
};
