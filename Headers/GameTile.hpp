#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class GameTile
{

public:
    bool collisions_on = false;
    sf::Vector2f pos;
    sf::Texture texture;
    sf::Sprite spr;
    GameTile(std::string textureName, float x, float y, bool collisions);
    bool setUpSprite(std::string textureName);
};
