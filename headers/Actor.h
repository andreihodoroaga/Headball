#ifndef OOP_ACTOR_H
#define OOP_ACTOR_H


#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Actor {
protected:
    std::string m_texturePath;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_position;
public:
    Actor(const std::string &texturePath, const sf::Vector2f &position);
    Actor(const Actor& other);
};


#endif //OOP_ACTOR_H
