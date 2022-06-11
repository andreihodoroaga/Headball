#include "../headers/Bot.h"
#include <cmath>
#include <random>

Bot::Bot(const std::string &texturePath, const sf::Vector2f &position, const float &movementSpeed) : Player(texturePath, position, movementSpeed), score(Score<int>(0)) {
    m_sprite.setColor(sf::Color(220, 20, 60));
}

Bot::Bot(const Bot &other) : Player(other) {
    std::cout << "Constructor de copiere Bot\n";
}

void Bot::goalBoundsCollision(sf::Vector2u windowSize, float goalWidth) {
    // only let the bot on the right part of the screen
    sf::FloatRect playerBounds = m_sprite.getGlobalBounds();
    if (playerBounds.left <= static_cast<float>(windowSize.x) - 300) {
        m_sprite.setPosition(static_cast<float>(windowSize.x) - 300, playerBounds.top);
    }
    // right goal collision
    else if (playerBounds.left + playerBounds.width >= static_cast<float>(windowSize.x) - goalWidth) {
        m_sprite.setPosition(static_cast<float>(windowSize.x) - goalWidth - playerBounds.width, playerBounds.top);
    }
}

std::shared_ptr<Player> Bot::clone() const {
    return std::make_shared<Bot>(*this);
}

void Bot::movePlayer(float x, float y) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 10.0);

    double randomNr = floor(dist(mt));

    if(randomNr == 1) {
        move(1.0f, 0.f); // move right
    }
    else if(randomNr == 2)
        move(-1.f, 0.f); // move left
    else
    if(randomNr == 3) {
        if(getPosition().y > 355)
            move(x, y);
    }
}

Bot::~Bot() {
    std::cout << "Destructor Bot\n";
}

void Bot::afiseazaScor() {
    std::cout << computeScore(static_cast<int>(std::floor(acceleration)));
}