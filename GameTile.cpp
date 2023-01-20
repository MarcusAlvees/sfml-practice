#include "Headers/GameTile.hpp"
#include "Headers/Global.hpp"

GameTile::GameTile(std::string textureName, float x, float y, bool collisions) {
    if(!setUpSprite(textureName))
    {
        return;
    }
    pos = sf::Vector2f(x, y);
    spr.setPosition(pos);
    collisions_on = collisions;
}

bool GameTile::setUpSprite(std::string textureName) {
    if(!texture.loadFromFile(textureName)) {
        return false;
    }
    spr.setTexture(texture);
    spr.setTextureRect(sf::IntRect(0, 0, CELL_SIZE, CELL_SIZE));
    return true;
}