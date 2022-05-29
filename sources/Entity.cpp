#include <iostream>
#include "../headers/Entity.h"
#include "../headers/Exception.h"

Entity::Entity(const std::string &texturePath, const sf::Vector2f &position) : m_texturePath(texturePath), m_position(position) {
    if(!m_texture.loadFromFile(m_texturePath)) {
        std::string arg = "Failed to load texture\n";
        throw FileError(arg);
    }
    m_texture.loadFromFile(m_texturePath);
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_position.x, m_position.y);
}

Entity::Entity(const Entity &other) : m_texturePath(other.m_texturePath), m_texture(other.m_texture), m_sprite(other.m_sprite), m_position(other.m_position){
    m_sprite.setTexture(m_texture);
    std::cout << "Constructor de copiere Entity\n";
}

Entity::~Entity() {
    std::cout << "Destructor Entity\n";
}
