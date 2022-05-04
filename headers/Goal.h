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

class Goal {
private:
    sf::Vector2f m_position;
    std::string m_texturePath;
    sf::Texture m_texture;
    sf::Sprite m_goal;
public:
    Goal(const std::string& texturePath, const sf::Vector2u& position);
    Goal(const Goal& other);
    Goal& operator=(const Goal& other);
    ~Goal();
    friend std::ostream& operator<<(std::ostream &os, const Goal& goal);
    const sf::Sprite& getSprite();
    void setPosition();
    float getWidth();
};


#endif //OOP_GOAL_H
