#pragma once

class Player
{
private:
    bool ground;

    const float GRAVITY = 9.8f; 
    float vertical_speed;
    float moveSpeed;
    sf::Vector2f velocity;
    sf::Vector2f playerGroundCheck;
    float right;
    float bottom;
    float left;
    int rows;


    sf::Clock dtClock;
    float deltaTime;

    sf::RectangleShape playerShape;
public:
    void initVariables();
    void initShape();
    Player();

    void updateWindowBounds(sf::RenderWindow& window);
    void playerSpeed(float horizontal);
    void gravity_calc();
    void collisionCheck();
    void updateDt();
    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
};

