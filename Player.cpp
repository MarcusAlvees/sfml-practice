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
    playerShape.setSize(sf::Vector2f(32.f, 64.f));
    playerShape.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
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
        velocity.y += ((deltaTime * GRAVITY) * 5)* deltaTime;
    }
    else { velocity.y = 0.f; }
}

void Player::collisionCheck() {
    sf::FloatRect playerCollisions = playerShape.getGlobalBounds();
    const sf::FloatRect playerBounds = playerShape.getGlobalBounds();

    playerGroundCheck = playerShape.getPosition();
    rows = ((playerShape.getPosition().y + playerShape.getSize().y) / CELL_SIZE) - 1;
    right = std::floor((((-camPos + playerShape.getPosition().x) + playerShape.getSize().x) - velocity.x) / CELL_SIZE);
    left = std::floor(((-camPos + playerShape.getPosition().x) - velocity.x) / CELL_SIZE);
    bottom = std::floor(((playerShape.getPosition().y + playerShape.getSize().y) + velocity.y) / CELL_SIZE);
    top = std::floor((playerShape.getPosition().y + velocity.y) / CELL_SIZE);

    //RIGHT AND LEFT COLLISSIONS
    if((map.tiles[(rows * 40) + right]->collisions_on == true || map.tiles[(((rows + 1) * 40)) + right]->collisions_on == true) || (map.tiles[left + (rows * 40)]->collisions_on == true || map.tiles[left + (((rows + 1) * 40))]->collisions_on == true))
    {
        velocity.x = 0.f;
    }
    
    //BOTTOM COLLISION
    if(playerShape.getPosition().y > 0.f && playerShape.getPosition().y < WINDOW_HEIGHT)
    {
        if((map.tiles[(bottom * 40) + (std::floor((-camPos + playerShape.getPosition().x) / CELL_SIZE))]->collisions_on == true && velocity.y > 0.f) || (map.tiles[(bottom * 40) + (std::floor(((-camPos + playerShape.getPosition().x) + playerShape.getSize().x) / CELL_SIZE))]->collisions_on == true && velocity.y > 0.f))
        {
            ground = true;
            amountOfJumps = 0;
            jumpTimer = 0.f;
            velocity.y = 0.f;
        }
        else {
            ground = false;
        }

        if((map.tiles[(top * 40) + (std::floor((-camPos + playerShape.getPosition().x) / CELL_SIZE))]->collisions_on == true && velocity.y < 0.f) || (map.tiles[(top * 40) + (std::floor(((-camPos + playerShape.getPosition().x) + playerShape.getSize().x) / CELL_SIZE))]->collisions_on == true && velocity.y < 0.f))
        {
            velocity.y = 0.f;
        }
    }
}

void Player::playerInputs() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { 
        velocity.x = -moveSpeed * deltaTime;
    } 
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { 
        velocity.x = moveSpeed * deltaTime;
    } else { velocity.x = 0.f; }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && amountOfJumps < 1) {
        if(jumpTimer > limitJump) {
            amountOfJumps++;
            return;
        }
        else{
            jumpTimer += deltaTime;
            velocity.y = PLAYER_JUMP_FORCE;
        }
    } else { amountOfJumps++; }
}

void Player::update(sf::RenderWindow& window){
    gravity_calc();
    playerInputs();
    collisionCheck();

    camPos += velocity.x;
    //std::cout << camPos;
    
    playerShape.move(0.f, velocity.y);

    updateDt();
    updateWindowBounds(window);
}

void Player::render(sf::RenderWindow& window) {
    window.draw(playerShape);
}
