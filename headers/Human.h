#ifndef OOP_HUMAN_H
#define OOP_HUMAN_H

#include "Player.h"

class Human : public Player {
public:
    Human(const std::string &texturePath, const sf::Vector2f &position, const float &movementSpeed);
    ~Human() override = default;
    void goalBoundsCollision(sf::Vector2u windowSize, float goalWidth) override;

    std::shared_ptr<Player> clone() const override;
};


#endif //OOP_HUMAN_H
