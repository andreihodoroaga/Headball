#ifndef OOP_WINDOW_H
#define OOP_WINDOW_H


#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Player.h"

class Window {
private:
    void Setup(const std::string& l_title,
               const sf::Vector2u& l_size);
    void Destroy();
    void Create();
    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone{};
    bool m_isFullscreen{};

public:
    Window();
    Window(const std::string& l_title, const sf::Vector2u& l_size);
    ~Window();
    void Clear(); // Clear the window.
    void Display(); // Display the changes.
    void Update(Player& player);
    bool IsDone() const;
//    bool IsFullscreen();
    sf::Vector2u GetWindowSize();
    void ToggleFullscreen();
    void Draw(const sf::Drawable& l_drawable);
};


#endif //OOP_WINDOW_H
