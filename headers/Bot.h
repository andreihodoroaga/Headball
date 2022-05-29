#ifndef OOP_BOT_H
#define OOP_BOT_H


#include "Player.h"

class Bot : public Player {
public:
    Bot(const std::string &texturePath, const sf::Vector2f &position, const float &movementSpeed);
    ~Bot() override {
        std::cout << "Destructor Bot\n";
    }
    Bot(const Bot& other);

    void goalBoundsCollision(sf::Vector2u windowSize, float goalWidth) override;
    void moveRandom();
    std::shared_ptr<Player> clone() const override;
};


#endif //OOP_BOT_H
