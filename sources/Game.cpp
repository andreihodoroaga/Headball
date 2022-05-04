#include <SFML/Window/Keyboard.hpp>
#include "../headers/Game.h"

Game::Game(): m_window("Headball", sf::Vector2u(800,600)){}
Game::~Game(){
    std::cout << "Destructor Game\n";
}
void Game::Update(){
    m_window.Update(player); // update window events
}
void Game::Render(){
    m_window.Clear();
    m_window.Draw(ball.getSprite());
    m_window.Draw(player.getSprite());
    m_window.Draw(goalRight.getSprite());
    m_window.Draw(goalLeft.getSprite());
    goalRight.setPosition(); // poarta din dreapta
    goalLeft.setPosition();  // poarta din stanga

    // player logic
    player.checkJumpFinish();
    player.goalBoundsCollision(m_window.GetWindowSize(), goalRight.getWidth());

    m_window.Display(); // Display.
}
Window& Game::GetWindow() {return m_window;}
void Game::HandleInput() {
    // keyboard input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.moveLeft();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.moveRight();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player.jump();
    }
}