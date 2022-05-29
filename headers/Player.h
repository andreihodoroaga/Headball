#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include "Entity.h"

class Player : public Entity {
private:
    float m_movementSpeed;

    // physics
    sf::Vector2f velocity;
    constexpr static const float velocityMax = 0.75f;
    constexpr static const float velocityMin = 0.05f;
    constexpr static const float acceleration = 0.85f;
    constexpr static const float drag = 0.1f;
    constexpr static const float gravity = 1.f;
    constexpr static const float velocityMaxY = 5.f;

public:
    Player(const std::string& texturePath, const sf::Vector2f& position, const float& movementSpeed);
    Player(const Player& other);
    Player& operator=(const Player& other);
    ~Player() override;
    friend std::ostream& operator<<(std::ostream &os, const Player& player);
    const sf::Sprite& getSprite();
    virtual std::shared_ptr<Player> clone() const = 0;
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    void scale(float x, float y);
    void resetVelocityY();
    void move(float dir_x, float dir_y);
    void updatePhysics();
    virtual void goalBoundsCollision(sf::Vector2u windowSize, float goalWidth) = 0;
};

#endif //OOP_PLAYER_H
