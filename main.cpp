#include <SFML/Graphics.hpp>
#include "headers/Game.h"
#include "headers/Exception.h"

int main()
{
    try {
        Game game;
        while(!game.GetWindow().IsDone()) {
            // Game loop
            game.HandleInput();
            game.Update();
            game.Render();
        }
    } catch (AppError &err) {
        std::cout << "The following error occured within the app:\n" << err.what() << "\n";
    } catch (std::exception &err) {
        std::cout << err.what() << "\n";
    }
    return 0;
}