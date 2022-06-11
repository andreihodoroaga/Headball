#include <SFML/Window/Keyboard.hpp>
#include "../headers/Game.h"
#include "../headers/Exception.h"

Game::Game(): m_window("Headball", sf::Vector2u(800,600)){
    checkPlayerInBounds(*human);
    checkPlayerInBounds(*bot);
}

Game::~Game(){
    std::cout << "Destructor Game\n";
}

Game &Game::get_Game() {
    static Game game;
    return game;
}

void Game::Update(){
    m_window.Update(); // update window events

    // check for the beginning of a new round
    if (startNewRound) {
        ball.setPosition(sf::Vector2f(350, 170));
        startNewRound = false;
    } else if(done) {
        DisplayWinner(*human); // apelez ca sa scap de warning din clang 11 :*
        done = false;
    }
    // human logic
    Update(*human);
    Update(*bot);
}


void Game::Update(Player &player_) {
    player_.updatePhysics();
    HandlePlayerCollision(player_);
    player_.goalBoundsCollision(m_window.GetWindowSize(), goalRight.getWidth());
}

void Game::Render(){
    m_window.Clear();
    m_window.Draw(ball.getSprite());
    m_window.Draw(human->getSprite());
    m_window.Draw(bot->getSprite());
    m_window.Draw(goalRight.getSprite());
    m_window.Draw(goalLeft.getSprite());
    m_window.Display(); // Display.
}
Window& Game::GetWindow() {return m_window;}
void Game::HandleInput() {
    // keyboard input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        human->movePlayer(-1.f, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        human->movePlayer(1.f, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        human->movePlayer(0.f, -1.f);
    }
    bot->movePlayer(0.f, -4.f);
}

void Game::HandlePlayerCollision(Player& player_) {
    // collision of the player with the bottom of the screen
    if(player_.getGlobalBounds().top > 364) {
        player_.resetVelocityY();
        player_.setPosition(player_.getGlobalBounds().left, 364);
    }
}

void Game::DisplayWinner(const Player &winner) {
    std::shared_ptr<Player> winnerClone = winner.clone();
    winnerClone->setPosition(500, 200);
    m_window.Draw(winnerClone->getSprite());
}

void Game::checkPlayerInBounds(Player& player) {
    if (player.getPosition().x > m_window.getSize().x || player.getPosition().x < 0 ||
            player.getPosition().y > m_window.getSize().y || player.getPosition().y < 0) {
        std::string arg = "The player is out of bounds\n";
        throw PlayerOutOfBounds(arg);
    }
}

