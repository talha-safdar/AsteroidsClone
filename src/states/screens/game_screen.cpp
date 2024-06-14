#include "game_screen.hpp"

GameScreen::GameScreen(sf::RenderWindow& window) : GameState(window)
{
}

void GameScreen::loadAssets()
{
}

void GameScreen::handleInput(sf::Event event)
{
}

void GameScreen::update(sf::Time dt)
{
}

void GameScreen::render(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);
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
