#include "Headers/GameTile.hpp"
#include "Headers/Global.hpp"

GameTile::GameTile(std::string textureName, float x, float y, bool collisions, bool drawNeeded) {
    if(!setUpSprite(textureName))
    {
        return;
    }
    pos = sf::Vector2f(x, y);
    collisions_on = collisions;
    needToDraw = drawNeeded;
}

bool GameTile::setUpSprite(std::string textureName) {
    if(textureName != " ")
    {
        if(!texture.loadFromFile(textureName)) {
            return false;
        }
        spr.setTexture(texture);
        spr.setTextureRect(sf::IntRect(0, 0, TEXTURE_CELL_SIZE, TEXTURE_CELL_SIZE));
        spr.setScale(sf::Vector2f(2.f, 2.f));
    }
    return true;
}