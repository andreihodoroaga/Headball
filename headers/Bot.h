#ifndef OOP_BOT_H
#define OOP_BOT_H


#include "Player.h"
#include "Score.h"

class Bot : public Player {
private:
    Score<int> score{};
public:
    Bot(const std::string &texturePath, const sf::Vector2f &position, const float &movementSpeed);
    ~Bot() override;
    Bot(const Bot& other);
    void movePlayer(float x, float y) override;
    void goalBoundsCollision(sf::Vector2u windowSize, float goalWidth) override;
    std::shared_ptr<Player> clone() const override;
    void afiseazaScor() override;
};


#endif //OOP_BOT_H
