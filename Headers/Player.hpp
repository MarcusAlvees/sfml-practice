#pragma once

class Player
{
private:
    bool ground;

    const float GRAVITY = 300.f; 
    float vertical_speed;
    float moveSpeed;
    sf::Vector2f velocity;
    sf::Vector2f playerGroundCheck;
    float right;
    float bottom;
    float bottomRight;
    float left;
    int rows;

    int amountOfJumps;
    float jumpTimer;
    float limitJump = 0.3f;


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
    void playerInputs();
    void updateDt();
    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
};

