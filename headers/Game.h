#ifndef OOP_GAME_H
#define OOP_GAME_H


#include "Window.h"
#include "Player.h"
#include "Ball.h"
#include "Goal.h"

class Game {
private:
    Window m_window;
    Ball ball{"./resources/ball1.png", sf::Vector2f(350, 170)};
    Player player{"./resources/player.png", sf::Vector2f(400, 364), 0.1f};
    Goal goalRight{"./resources/goal1.png", sf::Vector2f(718,330)};
    Goal goalLeft{"./resources/goal2.png", sf::Vector2f(0,330)};
    bool startNewRound = true;
public:
    Game();
    ~Game();
    void HandleInput();
    void Update();
    void Render();
    void HandlePlayerCollision();
    Window& GetWindow();
};


#endif //OOP_GAME_H
