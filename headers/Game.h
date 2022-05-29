#ifndef OOP_GAME_H
#define OOP_GAME_H


#include "Window.h"
#include "Player.h"
#include "Ball.h"
#include "Goal.h"
#include "Human.h"
#include "Bot.h"
class Game {
private:
    Window m_window;
    Ball ball{"./resources/ball1.png", sf::Vector2f(350, 170)};
    std::shared_ptr<Player> player = std::make_shared<Human>(Human{"./resources/player.png", sf::Vector2f(100, 364), 0.1f});
    std::shared_ptr<Player> bot = std::make_shared<Bot>(Bot{"./resources/bot.png", sf::Vector2f(618, 364), 0.1f});
    Goal goalLeft{"./resources/goal2.png", sf::Vector2f(0,330)};
    Goal goalRight{"./resources/goal1.png", sf::Vector2f(718,330)};
    bool startNewRound = true;
public:
    Game();
    ~Game();
    void HandleInput();
    void Update();
    void Update(Player& player_);
    void Render();
    void HandlePlayerCollision(Player& player_);
    [[maybe_unused]] void DisplayWinner(const Player& winner);
    Window& GetWindow();
};


#endif //OOP_GAME_H
