#include "../headers/Ball.h"

Ball::Ball(const std::string &texturePath, const sf::Vector2f& position) : Entity(texturePath, position) {
    std::cout << "Constructor de initializare Ball.\n";
}

Ball::Ball(const Ball &other) : Entity(other) {
    std::cout << "Constructor de copiere Ball.\n";
}

Ball &Ball::operator=(const Ball &other) {
    m_texturePath = other.m_texturePath;
    m_texture = other.m_texture;
    m_sprite = other.m_sprite;
    m_position = other.m_position;
    std::cout << "operator= de copiere Player.\n";
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

void Ball::move(const float dir_x, const float dir_y) {
//    std::cout << velocity.x << " " << velocity.y << " " << dir_y << "\n";
    // acceleration
    velocity.x += dir_x * acceleration;
    velocity.y += dir_y * (acceleration * 2);
    // limit velocity
    if (std::abs(velocity.x) > velocityMax) {
        // std::cout << velocity.x << " " << dir_y << "\n";
        velocity.x = velocityMax * ((velocity.x < 0) ? -1.f : 1.f);
    }
}

void Ball::updatePhysics() {
    // gravity
    velocity.y += gravity;
    if (std::abs(velocity.y) > velocityMaxY) {
        velocity.y = velocityMaxY * ((velocity.y < 0) ? -1.f : 1.f);
    }
    // deceleration
    velocity *= drag;

    // limit deceleration
    if (std::abs(velocity.x) < velocityMin)
        velocity.x = 0.f;
    if (std::abs(velocity.y) < velocityMin)
        velocity.y = 0.f;

    // std::cout << velocity.x << " " << velocity.y << "\n";

    // move the player
    m_sprite.move(velocity);
}