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
												isHolding = true;
        }
								else
								{
												isHolding = false;
								}
    }
				else if (event.type == sf::Event::MouseButtonReleased) {
								if (event.mouseButton.button == sf::Mouse::Left)
								{
												isHolding = false;
								}
				}
}

// logics
void GameScreen::update(sf::Time dt)
{
				if (isHolding == true) {
								sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
								circle.setPosition(mousePosition.x, mousePosition.y);
				}
}

void GameScreen::render(sf::RenderWindow& window)
{
				//if (isHolding != true) {
								window.clear(sf::Color::Black);
				//}

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
