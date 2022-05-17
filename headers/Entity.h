#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H


#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

class Entity {
protected:
    std::string m_texturePath;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_position;
public:
    Entity(const std::string &texturePath, const sf::Vector2f &position);
    Entity(const Entity& other);
    virtual std::shared_ptr<Entity> clone() const = 0;
    virtual ~Entity();
};


#endif //OOP_ENTITY_H
