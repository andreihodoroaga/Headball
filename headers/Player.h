#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include "Actor.h"

class Player : public Actor {
private:
    float m_movementSpeed;

    // gravity variables
    const float m_groundHeight = 364.f;
    const float m_gravitySpeed = 0.3f;
    bool m_isJumping = false;
    const float jumpSpeed = 0.2f;

    // physics
    sf::Vector2f velocity;
    float velocityMax;
    float velocityMin;
    float acceleration;
    float drag;
    float gravity;
    float velocityMaxY;

public:
    Player(const std::string& texturePath, const sf::Vector2f& position, const float& movementSpeed);
    [[maybe_unused]] Player(const Player& other);
    Player& operator=(const Player& other);
    ~Player();
    friend std::ostream& operator<<(std::ostream &os, const Player& player);
    const sf::Sprite& getSprite();
    void initPhysics();
    sf::FloatRect getGlobalBounds();
    void setPosition(float x, float y);
    void resetVelocityY();
    void move(float dir_x, float dir_y);
    void updatePhysics();
    void moveLeft();
    void moveRight();
    void jump();
    void setIsJumping(bool isJumping);
    void checkJumpFinish();
    void goalBoundsCollision(sf::Vector2u windowSize, float goalWidth);
};


#endif //OOP_PLAYER_H
