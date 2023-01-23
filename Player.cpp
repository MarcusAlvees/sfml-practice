#include <array>
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Headers/Player.hpp"
#include "Headers/DrawMap.hpp"

DrawMap map;

Player::Player() {
    initVariables();
    initShape();
}

void Player::initVariables() {
    this->moveSpeed = 400.f;
    DrawMap map;
    velocity.x = 0.f;
    velocity.y = 0.f;
}
void Player::initShape() {
    playerShape.setFillColor(sf::Color::Blue);
    playerShape.setSize(sf::Vector2f(50.f, 50.f));
    playerShape.setPosition(50.f, 0.f);
}

void Player::updateWindowBounds(sf::RenderWindow& window) {
    const sf::FloatRect playerBounds = playerShape.getGlobalBounds();
    if(playerBounds.left <= 0.f) {
        playerShape.setPosition(sf::Vector2f(0.f, playerShape.getPosition().y));
    }
    if(playerBounds.left + playerBounds.width >= window.getSize().x) {
        playerShape.setPosition(sf::Vector2f(window.getSize().x - playerBounds.width, playerShape.getPosition().y));
    }
    if(playerBounds.top <= 0.f) {
        playerShape.setPosition(sf::Vector2f(playerShape.getPosition().x, 0.f));
    }
    if(playerBounds.top + playerBounds.height >= window.getSize().y) {
        playerShape.setPosition(sf::Vector2f(playerShape.getPosition().x, window.getSize().y - playerBounds.height));
        //ground = true;
    }
}

void Player::updateDt() {
    deltaTime = dtClock.restart().asSeconds();
}

void Player::gravity_calc() {
    if(ground == false) {
        velocity.y += deltaTime * GRAVITY;
        
    }
    else { velocity.y = 0.f; }
}

void Player::collisionCheck() {
    sf::FloatRect playerCollisions = playerShape.getGlobalBounds();

    // for(int i; i < map.tiles.size(); i++) {
    //     sf::FloatRect tilesCollision = map.tiles[i]->spr.getGlobalBounds();
    //     sf::FloatRect next = playerCollisions;
    //     next.top += playerCollisions.height;
    //     //CHECK DOWN COLLISION
    //     if(next.intersects(tilesCollision)) {
    //         ground = true;
    //     } else { ground = false; }
    // }
    const sf::FloatRect playerBounds = playerShape.getGlobalBounds();

    playerGroundCheck = playerShape.getPosition();
    bottom = std::floor(((playerShape.getPosition().y + playerShape.getSize().y) + velocity.y) / CELL_SIZE);
    rows = ((playerShape.getPosition().y + playerShape.getSize().y) / CELL_SIZE) - 1;
    right = std::floor(((playerShape.getPosition().x + playerShape.getSize().x) + velocity.x) / CELL_SIZE);
    left = std::floor((playerShape.getPosition().x + velocity.x) / CELL_SIZE);

    if(map.tiles[(rows * 40) + right]->collisions_on == true)
    {
        std::cout << right;
        velocity.x = 0.f;
    }

    if(map.tiles[left + (rows * 40)]->collisions_on == true)
    {
        velocity.x = 0.f;
    }

    if(map.tiles[bottom * 40 + 1]->collisions_on == true)
    {
        ground = true;
        velocity.y = 0.f;
        std::cout << rows * 40 << "\n";

    }
    else {
        ground = false;
    }


    // if(map.tiles[x]->collisions_on == false) {
    //     ground = true;
    // } else {
    //     ground = false;
    // }
}

void Player::update(sf::RenderWindow& window){
    gravity_calc();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { 
        velocity.x = moveSpeed * deltaTime;
    } 
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { 
        velocity.x = -moveSpeed * deltaTime;
    } else { velocity.x = 0.f; }
    collisionCheck();
    
    playerShape.move(velocity);

    updateDt();
    updateWindowBounds(window);
}

void Player::render(sf::RenderWindow& window) {
    window.draw(playerShape);
}
