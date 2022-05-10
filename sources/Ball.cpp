#include "../headers/Ball.h"

Ball::Ball(const std::string &texturePath, const sf::Vector2f& position) : Actor(texturePath, position) {
    std::cout << "Constructor de initializare Ball.\n";
}

Ball::Ball(const Ball &other) : Actor(other) {
    std::cout << "Constructor de copiere Ball.\n";
}

Ball &Ball::operator=(const Ball &other) {
    m_texturePath = other.m_texturePath;
    m_position = other.m_position;
    std::cout << "operator= copiere Ball\n";
    return *this;
}

Ball::~Ball() {
    std::cout << "Destructor Ball.\n";
}

std::ostream &operator<<(std::ostream &os, const Ball &ball) {
    os << "Mingea foloseste imaginea " << ball.m_texturePath << "\n";
    return os;
}

const sf::Sprite &Ball::getSprite() {
    return m_sprite;
}

void Ball::setPosition(const sf::Vector2f& position) {
    m_sprite.setPosition(position.x, position.y);
}
