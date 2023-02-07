#pragma once

class Player
{
private:
    bool ground;

    const float GRAVITY = 300.f; 
    float vertical_speed;
    sf::Vector2f velocity;
    sf::Vector2f playerGroundCheck;
    float right;
    float bottom;
    float top;
    float left;
    int rows;

    int amountOfJumps;
    float jumpTimer;
    float limitJump = 0.3f;

    float speedClamp = 400.f;
    float moveSpeed;
    float moveAcceleration = 5.f;


    sf::Clock dtClock;
    float deltaTime;

    sf::RectangleShape playerShape;
public:
    float camPos;
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

