#include "../headers/Player.h"

Player::Player(const std::string &texturePath, const sf::Vector2f &position, const float &movementSpeed) : Actor(texturePath, position), m_movementSpeed{movementSpeed} {
    initPhysics();
    std::cout << "Constructor de initializare Player.\n";
}

[[maybe_unused]] Player::Player(const Player &other) : Actor(other), m_movementSpeed{other.m_movementSpeed}{
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

void Player::initPhysics() {
    velocityMax = 0.75f;
    velocityMin = 0.05f;
    acceleration = 0.85f;
    drag = 0.1f;
    gravity = 1.f;
    velocityMaxY = 2.f;
}

void Player::move(const float dir_x, const float dir_y) {
//    std::cout << velocity.x << " " << velocity.y << " " << dir_y << "\n";
    // acceleration
    velocity.x += dir_x * acceleration;
    velocity.y += dir_y * (acceleration * 2);

    // limit velocity
    if (std::abs(velocity.x) > velocityMax) {
//        std::cout << velocity.x << " " << dir_y << "\n";
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

//    std::cout << velocity.x << " " << velocity.y << "\n";

    // move the player
    m_sprite.move(velocity);
}

void Player::moveLeft() {
    m_sprite.move(-m_movementSpeed, 0.f);
}

void Player::moveRight() {
    m_sprite.move(m_movementSpeed, 0.f);
}

void Player::jump() {
    m_sprite.move(0, -jumpSpeed);
    m_isJumping = true;
}

void Player::setIsJumping(const bool isJumping) {
    m_isJumping = isJumping;
}

void Player::checkJumpFinish() {
    if (m_sprite.getPosition().y < m_groundHeight && !m_isJumping) {
        m_sprite.move(0, m_gravitySpeed);
    }
}

void Player::goalBoundsCollision(sf::Vector2u windowSize, float goalWidth) {
    // left goal collision
    sf::FloatRect playerBounds = m_sprite.getGlobalBounds();
    if (playerBounds.left <= goalWidth) {
        m_sprite.setPosition(goalWidth, playerBounds.top);
    }
    // right goal collision
    else if (playerBounds.left + playerBounds.width >= static_cast<float>(windowSize.x) - goalWidth) {
        m_sprite.setPosition(static_cast<float>(windowSize.x) - goalWidth - playerBounds.width, playerBounds.top);
    }
}
