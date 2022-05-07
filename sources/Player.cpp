#include "../headers/Player.h"

Player::Player(const std::string &texturePath, const float &movementSpeed, const sf::Vector2f &position) : m_texturePath{texturePath}, m_position{position}, m_movementSpeed{movementSpeed} {
    m_texture.loadFromFile(texturePath);
    m_player.setTexture(m_texture);
    m_player.setPosition(m_position.x, m_position.y);
    std::cout << "Constructor de initializare Player.\n";
}

[[maybe_unused]] Player::Player(const Player &other) : m_texturePath{other.m_texturePath}, m_position{other.m_position}, m_movementSpeed{other.m_movementSpeed}{
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
    return m_player;
}

void Player::moveLeft() {
    m_player.move(-m_movementSpeed, 0.f);
}

void Player::moveRight() {
    m_player.move(m_movementSpeed, 0.f);
}

void Player::jump() {
    m_player.move(0, -jumpSpeed);
    m_isJumping = true;
}

void Player::setIsJumping(const bool isJumping) {
    m_isJumping = isJumping;
}

void Player::checkJumpFinish() {
    if (m_player.getPosition().y < m_groundHeight && !m_isJumping) {
        m_player.move(0, m_gravitySpeed);
    }
}

void Player::goalBoundsCollision(sf::Vector2u windowSize, float goalWidth) {
    // left goal collision
    sf::FloatRect playerBounds = m_player.getGlobalBounds();
    if (playerBounds.left <= goalWidth) {
        m_player.setPosition(goalWidth, playerBounds.top);
    }
    // right goal collision
    else if (playerBounds.left + playerBounds.width >= static_cast<float>(windowSize.x) - goalWidth) {
        m_player.setPosition(static_cast<float>(windowSize.x) - goalWidth - playerBounds.width, playerBounds.top);
    }
}
