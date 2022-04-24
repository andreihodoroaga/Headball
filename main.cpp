#include <iostream>
#include <SFML/Graphics.hpp>

class Ball {
private:
    std::string m_texturePath;
    sf::Texture m_ballTexture;
    sf::Sprite m_ball;
    sf::Vector2i m_increment;
public:
    // constructor de initializare
    Ball(const std::string& texturePath, sf::Vector2i increment) : m_texturePath{texturePath}, m_increment{increment} {
        m_ballTexture.loadFromFile(texturePath);
        m_ball.setTexture(m_ballTexture);
        std::cout << "Constructor de initializare Ball.\n";
    }
    // constructor de copiere
    Ball(const Ball& other) : m_texturePath{other.m_texturePath}, m_increment{other.m_increment} {
        std::cout << "Constructor de copiere Ball.\n";
    }
    // operator= de copiere
    Ball& operator=(const Ball& other) {
        m_texturePath = other.m_texturePath;
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
        os << "Mingea foloseste imaginea " << ball.m_texturePath << "\n";
        return os;
    }
    // getter sprite
    const sf::Sprite& getSprite() {
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
    std::string m_texturePath;
    sf::Texture m_texture;
    sf::Sprite m_goal;
public:
    Goal(const std::string& texturePath, const sf::Vector2u& position) : m_position{position}, m_texturePath{texturePath} {
        m_texture.loadFromFile(texturePath);
        m_goal.setTexture(m_texture);
        std::cout << "Constructor de initializare Goal.\n";
    }
    Goal(const Goal& other) : m_position{other.m_position}, m_texturePath{other.m_texturePath} {
        std::cout << "Constructor de copiere Goal.\n";
    }
    Goal& operator=(const Goal& other) {
        m_position = other.m_position;
        m_texturePath = other.m_texturePath;
        std::cout << "operator= de copiere Goal.\n";
        return *this;
    }
    ~Goal() {
        std::cout << "Destructor Goal. \n";
    }
    friend std::ostream& operator<<(std::ostream &os, const Goal& goal) {
        os << "Poarta e pozitionata la (" << goal.m_position.x << "," << goal.m_position.y << ").\n";
        return os;
    }
    const sf::Sprite& getSprite() {
        return m_goal;
    }
    void setPosition() {
        m_goal.setPosition(m_position.x, m_position.y);
    }
    float getWidth() {
        return m_goal.getGlobalBounds().width;
    }
};

class Player {
private:
    std::string m_texturePath;
    sf::Texture m_texture;
    sf::Sprite m_player;
    float m_movementSpeed;
    // gravity variables
    const float m_groundHeight = 330.f;
    const float m_gravitySpeed = 0.3;
    bool m_isJumping = false;
    const float jumpSpeed = 0.2;

public:
    Player(const std::string& texturePath) : m_texturePath{texturePath} {
        m_texture.loadFromFile(texturePath);
        m_player.setTexture(m_texture);
        m_player.setPosition(300, 250);
        m_movementSpeed = 0.1;
        std::cout << "Constructor de initializare Player.\n";
    }
    Player(const Player& other) : m_texturePath{other.m_texturePath} {
        std::cout << "Constructor de copiere Player.\n";
    }
    Player& operator=(const Player& other) {
        m_texturePath = other.m_texturePath;
        std::cout << "operator= de copiere Player.\n";
        return *this;
    }
    ~Player() {
        std::cout << "Destructor Player.\n";
    }
    friend std::ostream& operator<<(std::ostream &os, const Player& player) {
        os << "Player texture path: " << player.m_texturePath << "\n";
        return os;
    }
    const sf::Sprite& getSprite() {
        return m_player;
    }
//    const sf::Vector2f& getPosition() {
//        return m_player.getPosition();
//    }
    void moveLeft() {
        m_player.move(-m_movementSpeed, 0.f);
    }
    void moveRight() {
        m_player.move(m_movementSpeed, 0.f);
    }
    void jump() {
        m_player.move(0, -jumpSpeed);
        m_isJumping = true;
    }
    void setIsJumping(const bool isJumping) {
        m_isJumping = isJumping;
    }
    void checkJumpFinish() {
        if (m_player.getPosition().y < m_groundHeight && !m_isJumping) {
            m_player.move(0, m_gravitySpeed);
        }
    }
    void goalBoundsCollision(sf::Vector2u windowSize, float goalWidth) {
        // left goal collision
        sf::FloatRect playerBounds = m_player.getGlobalBounds();
        if (playerBounds.left <= goalWidth) {
            m_player.setPosition(goalWidth, playerBounds.top);
        }
        // right goal collision
        else if (playerBounds.left + playerBounds.width >= windowSize.x - goalWidth) {
            m_player.setPosition(windowSize.x - goalWidth - playerBounds.width, playerBounds.top);
        }
    }
};

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
    Window(const std::string& l_title, const sf::Vector2u& l_size);
    ~Window();
    void Clear(); // Clear the window.
    void Display(); // Display the changes.
    void Update(Player& player);
    bool IsDone() const;
    bool IsFullscreen();
    sf::Vector2u GetWindowSize();
    void ToggleFullscreen();
    void Draw(sf::Drawable& l_drawable);
};
Window::Window(){
    Setup("Window", sf::Vector2u(640,480));
    m_window.setFramerateLimit(60);
}
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
void Window::Update(Player& player){
    sf::Event event{};
    while(m_window.pollEvent(event)){
        if(event.type == sf::Event::Closed) {
            m_isDone = true;
        }
        else if(event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::F11) {
            ToggleFullscreen();
        }
        else if (event.type == sf::Event::KeyReleased) {
            if(event.key.code == sf::Keyboard::W) {
                player.setIsJumping(false);
            }
        }
    }
}
void Window::ToggleFullscreen(){
    m_isFullscreen = !m_isFullscreen;
    Destroy();
    Create();
}
void Window::Clear(){ m_window.clear(sf::Color::Black); }
void Window::Display(){ m_window.display(); }
bool Window::IsDone() const{ return m_isDone; }
bool Window::IsFullscreen(){ return m_isFullscreen; }
sf::Vector2u Window::GetWindowSize(){ return m_windowSize; }
void Window::Draw(sf::Drawable& l_drawable){
    m_window.draw(l_drawable);
}

class Game {
private:
    Window m_window;
    Ball ball{"../../../resources/ball1.png", sf::Vector2i(1,1)};
    Player player{"../../../resources/player.gif"};
    Goal goalRight{"../../../resources/goal1.png", sf::Vector2u(718,330)};
    Goal goalLeft{"../../../resources/goal2.png", sf::Vector2u(0,330)};
public:
    Game();
    ~Game();
    void HandleInput();
    void Update();
    void Render();
    Window& GetWindow();
};
Game::Game(): m_window("Headball", sf::Vector2u(800,600)){}
Game::~Game(){
    std::cout << "Destructor Game\n";
}
void Game::Update(){
    m_window.Update(player); // update window events
}
void Game::Render(){
    m_window.Clear();
    m_window.Draw((sf::Drawable &) ball.getSprite());
    m_window.Draw((sf::Drawable &) player.getSprite());
    m_window.Draw((sf::Drawable &) goalRight.getSprite());
    m_window.Draw((sf::Drawable &) goalLeft.getSprite());
    goalRight.setPosition(); // poarta din dreapta
    goalLeft.setPosition();  // poarta din stanga

    // player logic
    player.checkJumpFinish();
    player.goalBoundsCollision(m_window.GetWindowSize(), goalRight.getWidth());

    m_window.Display(); // Display.
}
Window& Game::GetWindow() {return m_window;}
void Game::HandleInput() {
    // keyboard input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.moveLeft();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.moveRight();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player.jump();
    }
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