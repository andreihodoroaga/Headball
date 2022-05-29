#include "../headers/Human.h"

Human::Human(const std::string &texturePath, const sf::Vector2f &position, const float &movementSpeed) : Player(texturePath, position, movementSpeed) {}

Human::Human(const Human &other) : Player(other) {
    std::cout << "Constructor de copiere Human\n";
}

void Human::goalBoundsCollision(sf::Vector2u windowSize, float goalWidth) {
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

std::shared_ptr<Player> Human::clone() const {
    return std::make_shared<Human>(*this);
}

void Human::movePlayer(float x, float y) {
    move(x, y);
}

std::ostream &operator<<(std::ostream &os, const Human &human) {
    os << static_cast<const Player &>(human);
    return os;
}

