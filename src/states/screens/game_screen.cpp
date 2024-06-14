#include "game_screen.hpp"

GameScreen::GameScreen(sf::RenderWindow& window) : GameState(window)
{
}

void GameScreen::loadAssets()
{
    circle.setRadius(5);
    circle.setPointCount(30);
    sf::FloatRect bounds = circle.getLocalBounds(); // very useful to get local size (left, top, width, height)
    circle.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    circle.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    circle.setFillColor(sf::Color::Red);
}

// input handling
void GameScreen::handleInput(sf::Event event)
{
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
    else if (event.type == sf::Event::KeyPressed) // keyboard
    {
        if (event.key.code == sf::Keyboard::Escape || event.type == sf::Keyboard::Up)
        {
            window.close();
        }
    }
    else if (event.type == sf::Event::MouseButtonPressed) // mouse
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            if (circle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
            {
                std::cout << "Do nothing if clicked on circle" << std::endl;
                // shouldSwitch = true;
                // handle the click
            }
            else
            {
                circle.setPosition(mousePosition.x, mousePosition.y);
            }
        }
    }
}

// logics
void GameScreen::update(sf::Time dt)
{
}

void GameScreen::render(sf::RenderWindow& window)
{
    window.clear(sf::Color::Blue);
    window.draw(circle);
    window.display();
}



bool GameScreen::shouldSwitchScene() const
{
				return shouldSwitch;
}

void GameScreen::resetSwitchToGameScreenFlag()
{
    shouldSwitch = false;
}

GameStateType GameScreen::getNextSceneType() const
{
    return GameStateType::GameScreen;
}
