#include <SFML/Graphics.hpp>
#include "headers/Game.h"

int main()
{
    Game game;
    while(!game.GetWindow().IsDone()){
        // Game loop
        game.HandleInput();
        game.Update();
        game.Render();
    }
    return 0;
}