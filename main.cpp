#include <iostream>
#include <SFML/Graphics.hpp>

class Window{
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
    Window(const std::string& l_title,const sf::Vector2u& l_size);
    ~Window();
    void BeginDraw(); // Clear the window.
    void EndDraw(); // Display the changes.
    void Update();
    bool IsDone() const;
    bool IsFullscreen();
    sf::Vector2u GetWindowSize();
    void ToggleFullscreen();
    void Draw(sf::Drawable& l_drawable);
};
Window::Window(){ Setup("Window", sf::Vector2u(640,480)); }
Window::Window(const std::string& l_title,
               const sf::Vector2u& l_size)
{
    Setup(l_title,l_size);
}
Window::~Window(){ Destroy(); }
void Window::Setup(const std::string& l_title,
                   const sf::Vector2u& l_size)
{
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isFullscreen = false;
    m_isDone = false;
    Create();
}
void Window::Create(){
    auto style = (m_isFullscreen ? sf::Style::Fullscreen
                                 : sf::Style::Default);
    m_window.create({ m_windowSize.x, m_windowSize.y, 32 },
                    m_windowTitle, style);
}
void Window::Destroy(){
    m_window.close();
}
void Window::Update(){
    sf::Event event{};
    while(m_window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            m_isDone = true;
        } else if(event.type == sf::Event::KeyPressed &&
                  event.key.code == sf::Keyboard::F5)
        {
            ToggleFullscreen();
        }
    }
}
void Window::ToggleFullscreen(){
    m_isFullscreen = !m_isFullscreen;
    Destroy();
    Create();
}
void Window::BeginDraw(){ m_window.clear(sf::Color::Black); }
void Window::EndDraw(){ m_window.display(); }
bool Window::IsDone() const{ return m_isDone; }
bool Window::IsFullscreen(){ return m_isFullscreen; }
sf::Vector2u Window::GetWindowSize(){ return m_windowSize; }
void Window::Draw(sf::Drawable&l_drawable){
    m_window.draw(l_drawable);
}

class Ball {
private:
    std::string m_ballPng;
    sf::Texture m_ballTexture;
    sf::Sprite m_ball;
    sf::Vector2i m_increment;
public:
    // constructor de initializare
    Ball(const std::string& ballPng, sf::Vector2i increment) : m_ballPng{ballPng}, m_increment{increment} {
        m_ballTexture.loadFromFile(ballPng);
        m_ball.setTexture(m_ballTexture);
        std::cout << "Constructor de initializare Ball.\n";
    }
    // constructor de copiere
    Ball(const Ball& other) : m_ballPng{other.m_ballPng}, m_increment{other.m_increment} {
        std::cout << "Constructor de copiere Ball.\n";
    }
    // operator= de copiere
    Ball& operator=(const Ball& other) {
        m_ballPng = other.m_ballPng;
        m_increment = other.m_increment;
        std::cout << "operator= copiere Ball\n";
        return *this;
    }
    // destructor
    ~Ball() {
        std::cout << "Destructor Ball.\n";
    }
    // operator<<
    friend std::ostream& operator<<(std::ostream &os, const Ball& ball) {
        os << "Mingea foloseste imaginea " << ball.m_ballPng << "\n";
        return os;
    }
    // getter textura
    const sf::Sprite& getTexture() {
        return m_ball;
    }
    // miscare minge
    void Move() {
        m_ball.setPosition(sf::Vector2f(100, 200));

    }
};

class Goal {
private:
    sf::Vector2f m_position;
    std::string m_pngPath;
    sf::Texture m_texture;
    sf::Sprite m_goal;
public:
    Goal(const std::string& pngPath, const sf::Vector2u& position) : m_position{position}, m_pngPath{pngPath} {
        m_texture.loadFromFile(pngPath);
        m_goal.setTexture(m_texture);
        std::cout << "Constructor de initializare Goal.\n";
    }
    Goal(const Goal& other) : m_position{other.m_position}, m_pngPath{other.m_pngPath} {
        std::cout << "Constructor de copiere Goal.\n";
    }
    Goal& operator=(const Goal& other) {
        m_position = other.m_position;
        m_pngPath = other.m_pngPath;
        std::cout << "operator= de copiere Goal.\n";
        return *this;
    }
    ~Goal() {
        std::cout << "Destructor Goal. \n";
    }
    friend std::ostream& operator<<(std::ostream &os, const Goal& goal) {
        os << "Mingea e pozitionata la (" << goal.m_position.x << "," << goal.m_position.y << ").\n";
        return os;
    }
    const sf::Sprite& getTexture() {
        return m_goal;
    }
    void setPosition() {
        m_goal.setPosition(m_position.x, m_position.y);
    }
};

class Player {
private:
    std::string m_pngPath;
    sf::Texture m_texture;
    sf::Sprite m_player;
public:
    Player(const std::string& pngPath) :m_pngPath{pngPath} {
        m_texture.loadFromFile(pngPath);
        m_player.setTexture(m_texture);
        m_player.setPosition(300, 300);
        std::cout << "Constructor de initializare Player.\n";
    }
    Player(const Player& other) : m_pngPath{other.m_pngPath} {
        std::cout << "Constructor de copiere Goal.\n";
    }
    Player& operator=(const Player& other) {
        m_pngPath = other.m_pngPath;
        std::cout << "operator= de copiere Goal.\n";
        return *this;
    }
    ~Player() {
        std::cout << "Destructor Goal. \n";
    }
    friend std::ostream& operator<<(std::ostream &os, const Player& player) {
        os << "Player png: " << player.m_pngPath << "\n";
        return os;
    }
    const sf::Sprite& getTexture() {
        return m_player;
    }
};

class Game {
private:
    Window m_window;
    Ball ball{R"(C:\Users\user\Desktop\POO\Headball\resources\ball1.png)", sf::Vector2i(1,1)};
    Player player{R"(C:\Users\user\Desktop\POO\Headball\resources\player.gif)"};
    Goal goalRight{R"(C:\Users\user\Desktop\POO\Headball\resources\goal1.png)", sf::Vector2u(718,330)};
    Goal goalLeft{R"(C:\Users\user\Desktop\POO\Headball\resources\goal2.png)", sf::Vector2u(0,330)};
public:
    Game();
    ~Game();
    void HandleInput();
    void Update();
    void Render();
    Window& GetWindow();
};
Game::Game(): m_window("Chapter 2", sf::Vector2u(800,600)){}
Game::~Game(){
    std::cout << "Destructor Game\n";
}
void Game::Update(){
    m_window.Update(); // update window events
}
void Game::Render(){
    m_window.BeginDraw();
    m_window.Draw((sf::Drawable &) ball.getTexture());
    m_window.Draw((sf::Drawable &) player.getTexture());
    m_window.Draw((sf::Drawable &) goalRight.getTexture());
    m_window.Draw((sf::Drawable &) goalLeft.getTexture());
    goalRight.setPosition(); // poarta din dreapta
    goalLeft.setPosition();  // poarta din stanga
    ball.Move();
    m_window.EndDraw(); // Display.
}
Window& Game::GetWindow() {return m_window;}
void Game::HandleInput() {
}

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