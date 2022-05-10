//
// Created by user on 04.05.2022.
//

#include "../headers/Goal.h"

Goal::Goal(const std::string &texturePath, sf::Vector2<float> position) : Actor(texturePath, position) {
    std::cout << "Constructor de initializare Goal.\n";
}

Goal::Goal(const Goal &other) : Actor(other) {
    std::cout << "Constructor de copiere Goal.\n";
}

Goal &Goal::operator=(const Goal &other) {
    m_position = other.m_position;
    m_texturePath = other.m_texturePath;
    std::cout << "operator= de copiere Goal.\n";
    return *this;
}

Goal::~Goal() {
    std::cout << "Destructor Goal. \n";
}

std::ostream &operator<<(std::ostream &os, const Goal &goal) {
    os << "Poarta e pozitionata la (" << goal.m_position.x << "," << goal.m_position.y << ").\n";
    return os;
}

const sf::Sprite &Goal::getSprite() {
    return m_sprite;
}

float Goal::getWidth() {
    return m_sprite.getGlobalBounds().width;
}
