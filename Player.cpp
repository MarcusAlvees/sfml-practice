#include <array>
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Headers/Player.hpp"

Player::Player() {
    initVariables();
    initShape();
}

void Player::initVariables() {
    this->moveSpeed = 400.f;
}
void Player::initShape() {
    playerShape.setFillColor(sf::Color::Blue);
    playerShape.setSize(sf::Vector2f(50.f, 50.f));
    playerShape.setPosition(0.f, 0.f);
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
        ground = true;
    }
}

void Player::updateDt() {
    deltaTime = dtClock.restart().asSeconds();
}

void Player::gravity_calc() {
    if(ground == false) {
        vertical_speed += deltaTime * GRAVITY;
        playerShape.move(0.f, vertical_speed);
    }
    else { vertical_speed = 0.f; }
}

void Player::update(sf::RenderWindow& window){
    gravity_calc();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { 
        playerShape.move( moveSpeed * deltaTime, 0.f);
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { 
        playerShape.move( -moveSpeed * deltaTime, 0.f);
    } 
    
    updateDt();
    updateWindowBounds(window);
}

void Player::render(sf::RenderWindow& window) {
    window.draw(playerShape);
}
