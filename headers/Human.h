#ifndef OOP_HUMAN_H
#define OOP_HUMAN_H

#include <ostream>
#include "Player.h"
#include "Score.h"

class Human : public Player {
private:
    // score
    Score<float> score;
public:
    Human(const std::string &texturePath, const sf::Vector2f &position, const float &movementSpeed);
    ~Human() override = default;
    Human(const Human& other);
    void goalBoundsCollision(sf::Vector2u windowSize, float goalWidth) override;
    friend std::ostream &operator<<(std::ostream &os, const Human &human);
    void movePlayer(float x, float y) override;
    std::shared_ptr<Player> clone() const override;
    void afiseazaScor() override;
};


#endif //OOP_HUMAN_H
