#include <SFML/Window/Keyboard.hpp>
#include "../headers/Game.h"

Game::Game(): m_window("Headball", sf::Vector2u(800,600)){}
Game::~Game(){
    std::cout << "Destructor Game\n";
}
void Game::Update(){
    player.updatePhysics();
    m_window.Update(player); // update window events

    // check for the beginning of a new round
    if (startNewRound) {
        ball.setPosition(sf::Vector2f(350, 170));
        startNewRound = false;
    }
    // player logic
    HandlePlayerCollision();
//    player.checkJumpFinish();
//    player.goalBoundsCollision(m_window.GetWindowSize(), goalRight.getWidth());
}
void Game::Render(){
    m_window.Clear();
    m_window.Draw(ball.getSprite());
    m_window.Draw(player.getSprite());
    m_window.Draw(goalRight.getSprite());
    m_window.Draw(goalLeft.getSprite());
    m_window.Display(); // Display.
}
Window& Game::GetWindow() {return m_window;}
void Game::HandleInput() {
    // keyboard input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.move(-1.f, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.move(1.f, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player.move(0.f, -1.f);
    }
}

void Game::HandlePlayerCollision() {
    // collision of player with the bottom of the screen
    if(player.getGlobalBounds().top > 364) {
        player.resetVelocityY();
        player.setPosition(player.getGlobalBounds().left, 364);
    }
}
