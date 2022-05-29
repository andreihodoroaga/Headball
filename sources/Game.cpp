#include <SFML/Window/Keyboard.hpp>
#include "../headers/Game.h"
#include "../headers/Exception.h"

Game::Game(): m_window("Headball", sf::Vector2u(800,600)){
    if (player.getPosition().x > m_window.getSize().x || player.getPosition().x < 0 ||
        player.getPosition().y > m_window.getSize().y || player.getPosition().y < 0) {
        std::string arg = "The player is out of bounds\n";
        throw PlayerOutOfBounds(arg);
    }
    DisplayWinner(bot);
}
Game::~Game(){
    std::cout << "Destructor Game\n";
}
void Game::Update(){
    m_window.Update(); // update window events

    player.updatePhysics();
    bot.updatePhysics();

    // check for the beginning of a new round
    if (startNewRound) {
        ball.setPosition(sf::Vector2f(350, 170));
        startNewRound = false;
    }
    // player logic
    HandlePlayerCollision();

    player.goalBoundsCollision(m_window.GetWindowSize(), goalRight.getWidth());
    bot.goalBoundsCollision(m_window.GetWindowSize(), goalRight.getWidth());
}
void Game::Render(){
    m_window.Clear();
    m_window.Draw(ball.getSprite());
    m_window.Draw(player.getSprite());
    m_window.Draw(bot.getSprite());
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
    bot.moveRandom();
}

void Game::HandlePlayerCollision() {
    // collision of player with the bottom of the screen
    if(player.getGlobalBounds().top > 364) {
        player.resetVelocityY();
        player.setPosition(player.getGlobalBounds().left, 364);
    }
    if(bot.getGlobalBounds().top > 364) {
        bot.resetVelocityY();
        bot.setPosition(bot.getGlobalBounds().left, 364);
    }
}

void Game::DisplayWinner(Player &winner) {
    std::shared_ptr<Player> winnerClone = winner.clone();
    winnerClone->setPosition(500, 200);
    m_window.Draw(winnerClone->getSprite());
}
