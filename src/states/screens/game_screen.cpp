#include <filesystem>
#include <iostream>
#include "game_screen.hpp"
#define SPEED_CHARACTER 10

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

	std::filesystem::path absolutePath1 = std::filesystem::absolute("assets/media/images/astronaut.png");
	std::cout << absolutePath1 << std::endl;
	if (astronautTxr.loadFromFile(absolutePath1.string()) == false)
	{
		std::cout << "Loading failed" << std::endl;
		// also add visual error
	}
	else
	{
		std::cout << "Button texture size: " << astronautTxr.getSize().x << " x " << astronautTxr.getSize().y << std::endl;
	}
	astronautTxr.setSmooth(true); // smoothness
	astronautSprt.setTexture(astronautTxr);
	astronautSprt.setScale(sf::Vector2f(0.15, 0.15));
	sf::FloatRect bounds2 = astronautSprt.getLocalBounds();
	astronautSprt.setOrigin(bounds2.left + bounds2.width / 2.f, bounds2.top + bounds2.height / 2.f);
	// astronautSprt.setOrigin(500, 500); // for mouse
	astronautSprt.setPosition(window.getSize().x / 2, window.getSize().y / 2);
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
		if (event.key.code == sf::Keyboard::Escape)
		{
			window.close();
		}
		if (event.key.code == sf::Keyboard::Up)
		{
			moveUpTrigger = true;
		}
		if (event.key.code == sf::Keyboard::Right)
		{
			moveRightTrigger = true;
		}
		if (event.key.code == sf::Keyboard::Down)
		{
			moveDownTrigger = true;
		}
		if (event.key.code == sf::Keyboard::Left)
		{
			moveLeftTrigger = true;
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
	if (isHolding == true) 
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		astronautSprt.setPosition(mousePosition.x, mousePosition.y);
	}
	if (moveUpTrigger)
	{
		moveUp();
		if (moveUpTrigger && moveRightTrigger)
		{
			moveUp();
			moveRight();
		}
	}
	if (moveRightTrigger)
	{
		astronautSprt.setPosition(astronautSprt.getPosition().x + SPEED_CHARACTER, astronautSprt.getPosition().y);
		moveRightTrigger = false;
	}
	if (moveDownTrigger)
	{
		astronautSprt.setPosition(astronautSprt.getPosition().x, astronautSprt.getPosition().y + SPEED_CHARACTER);
		moveDownTrigger = false;
	}
	if (moveLeftTrigger)
	{
		astronautSprt.setPosition(astronautSprt.getPosition().x - SPEED_CHARACTER, astronautSprt.getPosition().y);
		moveLeftTrigger = false;
	}
}

void GameScreen::render(sf::RenderWindow& window)
{
	//if (isHolding != true) {
	window.clear(sf::Color::Black);
	//}

	window.draw(astronautSprt);
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

void GameScreen::moveUp() 
{
	astronautSprt.setPosition(astronautSprt.getPosition().x, astronautSprt.getPosition().y - SPEED_CHARACTER);
	moveUpTrigger = false;
}

void GameScreen::moveRight() 
{
	astronautSprt.setPosition(astronautSprt.getPosition().x + SPEED_CHARACTER, astronautSprt.getPosition().y);
	moveRightTrigger = false;
}

void GameScreen::moveDown() 
{
	astronautSprt.setPosition(astronautSprt.getPosition().x, astronautSprt.getPosition().y + SPEED_CHARACTER);
	moveDownTrigger = false;
}

void GameScreen::moveLeft() 
{
	astronautSprt.setPosition(astronautSprt.getPosition().x - SPEED_CHARACTER, astronautSprt.getPosition().y);
	moveLeftTrigger = false;
}
