#ifndef OOP_BALL_H
#define OOP_BALL_H


#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <memory>
#include "Entity.h"

class Ball : public Entity{
private:
    // physics
    sf::Vector2f velocity;
    float velocityMax = 0.75f;
    float velocityMin = 0.05f;
    float acceleration = 0.85;
    float drag = 0.1f;
    float gravity = 1.f;
    float velocityMaxY = 2.f;
public:
    // constructor de initializare
    Ball(const std::string& texturePath, const sf::Vector2f& position);
    // constructor de copiere
    Ball(const Ball& other);
    // operator= de copiere
    Ball& operator=(const Ball& other);
    // destructor
    ~Ball();
    // operator<<
    friend std::ostream& operator<<(std::ostream &os, const Ball& ball);
    // getter sprite
    const sf::Sprite& getSprite();
    void setPosition(const sf::Vector2f& position);
    // ball movement
    void move(float dir_x, float dir_y);
    void updatePhysics();
};


#endif //OOP_BALL_H
