//
// Created by user on 04.05.2022.
//

#ifndef OOP_GOAL_H
#define OOP_GOAL_H


#include <SFML/System/Vector2.hpp>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <memory>
#include "Entity.h"

class Goal : public Entity {
public:
    Goal(const std::string& texturePath, sf::Vector2<float> position);
    Goal(const Goal& other);
    Goal& operator=(const Goal& other);
    ~Goal() override;
    friend std::ostream& operator<<(std::ostream &os, const Goal& goal);
    const sf::Sprite& getSprite();
    float getWidth();
};

class GoalFactory {
public:
    static Goal GoalLeft() {return {"./resources/goal2.png", sf::Vector2f(0,330)};}
    static Goal GoalRight() {return {"./resources/goal1.png", sf::Vector2f(718,330)};}
};

#endif //OOP_GOAL_H
