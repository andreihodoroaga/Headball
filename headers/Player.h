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
    sf::Vector2f m_position;
    float m_movementSpeed;

    // gravity variables
    const float m_groundHeight = 364.f;
    const float m_gravitySpeed = 0.3f;
    bool m_isJumping = false;
    const float jumpSpeed = 0.2f;

public:
    Player(const std::string& texturePath, const float& movementSpeed, const sf::Vector2f& position);
    [[maybe_unused]] Player(const Player& other);
    Player& operator=(const Player& other);
    ~Player();
    friend std::ostream& operator<<(std::ostream &os, const Player& player);
    const sf::Sprite& getSprite();
    void moveLeft();
    void moveRight();
    void jump();
    void setIsJumping(bool isJumping);
    void checkJumpFinish();
    void goalBoundsCollision(sf::Vector2u windowSize, float goalWidth);
};


#endif //OOP_PLAYER_H
