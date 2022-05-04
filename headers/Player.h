//
// Created by user on 04.05.2022.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>

class Player {
private:
    std::string m_texturePath;
    sf::Texture m_texture;
    sf::Sprite m_player;
    float m_movementSpeed;
    // gravity variables
    const float m_groundHeight = 330.f;
    const float m_gravitySpeed = static_cast<float>(0.3);
    bool m_isJumping = false;
    const float jumpSpeed = static_cast<float>(0.2);

public:
    Player(const std::string& texturePath, const float& movementSpeed);
    Player(const Player& other);
    Player& operator=(const Player& other);
    ~Player();
    friend std::ostream& operator<<(std::ostream &os, const Player& player);
    const sf::Sprite& getSprite();
    void moveLeft();
    void moveRight();
    void jump();
    void setIsJumping(const bool isJumping);
    void checkJumpFinish();
    void goalBoundsCollision(sf::Vector2u windowSize, float goalWidth);
};


#endif //OOP_PLAYER_H
