#ifndef OOP_GAME_H
#define OOP_GAME_H


#include "Window.h"
#include "Player.h"
#include "Ball.h"
#include "Goal.h"

class Game {
private:
    Window m_window;
    Ball ball{"./resources/ball1.png", sf::Vector2i(1,1)};
    Player player{"./resources/player.gif", 0.1f};
    Goal goalRight{"./resources/goal1.png", sf::Vector2u(718,330)};
    Goal goalLeft{"./resources/goal2.png", sf::Vector2u(0,330)};
public:
    Game();
    ~Game();
    void HandleInput();
    void Update();
    void Render();
    Window& GetWindow();
};


#endif //OOP_GAME_H
