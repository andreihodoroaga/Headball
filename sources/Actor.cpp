#include <iostream>
#include "../headers/Actor.h"

Actor::Actor(const std::string &texturePath, const sf::Vector2f &position) : m_texturePath(texturePath), m_position(position) {
    m_texture.loadFromFile(m_texturePath);
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_position.x, m_position.y);
}

Actor::Actor(const Actor &other) : m_texturePath(other.m_texturePath), m_texture(other.m_texture) ,m_position(other.m_position){
    std::cout << "Constructor de copiere Actor\n";
}
