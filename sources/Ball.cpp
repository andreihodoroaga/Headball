#include "../headers/Ball.h"

Ball::Ball(const std::string &texturePath, sf::Vector2i increment) : m_texturePath{texturePath}, m_increment{increment} {
    m_ballTexture.loadFromFile(texturePath);
    m_ball.setTexture(m_ballTexture);
    std::cout << "Constructor de initializare Ball.\n";
}

Ball::Ball(const Ball &other) : m_texturePath{other.m_texturePath}, m_increment{other.m_increment} {
    std::cout << "Constructor de copiere Ball.\n";
}

Ball &Ball::operator=(const Ball &other) {
    m_texturePath = other.m_texturePath;
    m_increment = other.m_increment;
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
    return m_ball;
}
