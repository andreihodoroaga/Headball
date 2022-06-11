#include "../headers/Player.h"
#include "../headers/Score.h"

Player::Player(const std::string &texturePath, const sf::Vector2f &position, const float &movementSpeed) : Entity(texturePath, position), m_movementSpeed{movementSpeed} {
    std::cout << "Constructor de initializare Player.\n";
}

Player::Player(const Player &other) : Entity(other), m_movementSpeed{other.m_movementSpeed}, velocity{other.velocity}{
    std::cout << "Constructor de copiere Player.\n";
}


Player &Player::operator=(const Player &other) {
    m_texturePath = other.m_texturePath;
    m_movementSpeed = other.m_movementSpeed;
    std::cout << "operator= de copiere Player.\n";
    return *this;
}

Player::~Player() {
    std::cout << "Destructor Player.\n";
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "Player texture path: " << player.m_texturePath << "\n";
    return os;
}

const sf::Sprite &Player::getSprite() {
    return m_sprite;
}

sf::FloatRect Player::getGlobalBounds() {
    return m_sprite.getGlobalBounds();
}

void Player::setPosition(const float x, const float y) {
    m_sprite.setPosition(x, y);
}

void Player::resetVelocityY() {
    velocity.y = 0.f;
}

void Player::move(const float dir_x, const float dir_y) {
//    std::cout << velocity.x << " " << velocity.y << " " << dir_y << "\n";
    // acceleration
    velocity.x += dir_x * acceleration;
    velocity.y += dir_y * (acceleration * 2);

    // limit velocity
    if (std::abs(velocity.x) > velocityMax) {
        velocity.x = velocityMax * ((velocity.x < 0) ? -1.f : 1.f);
    }
}

void Player::updatePhysics() {
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

    // move the player
    m_sprite.move(velocity);
}

sf::Vector2f Player::getPosition() {
    return m_sprite.getPosition();
}

void Player::scale(float x, float y) {
    m_sprite.scale(x, y);
}

[[maybe_unused]] void Player::addGoal() {
    nrGoals++;
}
