#pragma once

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void handleInputMouse(sf::Mouse::Button button, bool bIsPressed);

private:
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;
};
