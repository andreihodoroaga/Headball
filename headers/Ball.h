#ifndef OOP_BALL_H
#define OOP_BALL_H


#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>

class Ball {
private:
    std::string m_texturePath;
    sf::Texture m_ballTexture;
    sf::Sprite m_ball;
    sf::Vector2f m_position;
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
    // miscare minge
//    void Move() {
//        m_ball.setPosition(sf::Vector2f(100, 200));
//    }
    void setPosition(const sf::Vector2f& position);
};


#endif //OOP_BALL_H
