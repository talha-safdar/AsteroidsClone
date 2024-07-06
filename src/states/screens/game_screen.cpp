#include <filesystem>
#include <iostream>
#include "game_screen.hpp"
#define SPEED_CHARACTER 10

GameScreen::GameScreen(sf::RenderWindow& window) : GameState(window)
{
}

void GameScreen::loadAssets()
{
	// close button
	GameState::addCloseButton(); // abstracted from GameState

	// aiming line ###

	// ###############

	// aiming ###
	// texture
	std::filesystem::path absolutePath = std::filesystem::absolute("assets/media/images/aim.png");
	if (aimtexture.loadFromFile(absolutePath.string()) == false)
	{
		std::cout << "Loading failed" << std::endl;
	// also add visual error
	}
	aimtexture.setSmooth(true);

	// sprite
	aimSprite.setTexture(aimtexture);
	aimSprite.setPosition(420, 115);
	aimSprite.setScale(0.1, 0.1);
	aimSprite.setOrigin(aimSprite.getLocalBounds().width / 2, aimSprite.getLocalBounds().height / 2);
	// ##########

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
	}
	else if (event.type == sf::Event::MouseButtonPressed) // mouse
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		if (GameScreen::CloseBtnSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
		{
			window.close();
		}
		else if (event.mouseButton.button == sf::Mouse::Left)
		{
			window.setMouseCursorVisible(false);
			isHolding = true;
		}
	}
	else if (event.type == sf::Event::MouseButtonReleased) {
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			window.setMouseCursorVisible(true);
			isHolding = false;
		}
	}
}

// logics
void GameScreen::update(sf::Time dt)
{
	// keyboard
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
	{
		moveUp();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			moveRight();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			moveLeft();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		moveRight();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			moveUp();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			moveDown();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		moveDown();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			moveRight();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			moveLeft();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		moveLeft();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			moveDown();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			moveUp();
		}
	}

	// mouse
	if (isHolding)
	{
		// aim
		// TO BE FIXED USING DELTA TIME
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

		//std::cout << "aim X: " << aimSprite.getPosition().x << std::endl;
		//std::cout << "astr X: " << astronautSprt.getPosition().x << std::endl;
		//std::cout << "MOUSE X: " << mousePosition.x << std::endl;
		// limit aim reach
		/*
		* if the aiming is less than the position of astronaut multiplied by 1.5
		* then continue to reposition else stop
		* multiplication *: towards right/down
		* division /: towards left/up
		*/
		// X axis ##########
		if (!reachedXLeft)
		{
			if (aimSprite.getPosition().x < astronautSprt.getPosition().x * 1.5 || mousePosition.x < aimSprite.getPosition().x)
			{
				std::cout << "R IF " << mousePosition.x << std::endl;
				reachedXRight = false;
				aimSprite.setPosition(mousePosition.x, mousePosition.y);
			}
			else
			{
				// std::cout << "R ELSE " << mousePosition.x << " " << reachedXRight << std::endl;
				reachedXRight = true;
				// keep sliding perpendiclualry
				aimSprite.setPosition(aimSprite.getPosition().x, mousePosition.y); // THIS LINE IS REPEATED !!!
			}
			std::cout << "R ELSE " << mousePosition.x << " " << reachedXRight << std::endl;
		}
		if (!reachedXRight)
		{
			// std::cout << "L IF CALC: " << aimSprite.getPosition().x << " " << astronautSprt.getPosition().x / 1.5 << std::endl;
			if (aimSprite.getPosition().x > astronautSprt.getPosition().x / 1.5 || mousePosition.x > aimSprite.getPosition().x)
			{
				std::cout << "L IF " << mousePosition.x << std::endl;
				reachedXLeft = false;
				aimSprite.setPosition(mousePosition.x, mousePosition.y);
			}
			else
			{
				std::cout << "L ELSE " << mousePosition.x << std::endl;
				reachedXLeft = true;
				// keep sliding perpendiclualry
				aimSprite.setPosition(aimSprite.getPosition().x, mousePosition.y);
			}
		}
		// #################

		// Y axis #########
		//if (!reachedYDown)
		//{
		//	if (aimSprite.getPosition().y < astronautSprt.getPosition().y * 1.5 || mousePosition.y < aimSprite.getPosition().y)
		//	{
		//		// std::cout << "R IF " << mousePosition.x << std::endl;
		//		reachedYUp = false;
		//		aimSprite.setPosition(mousePosition.x, mousePosition.y);
		//	}
		//	else
		//	{
		//		// std::cout << "R ELSE " << mousePosition.x << std::endl;
		//		reachedYUp = true;
		//		// keep sliding perpendiclualry
		//		aimSprite.setPosition(mousePosition.x, aimSprite.getPosition().y);
		//	}
		//}
		//if (!reachedYUp)
		//{
		//	// std::cout << "L IF CALC: " << aimSprite.getPosition().x << " " << astronautSprt.getPosition().x / 1.5 << std::endl;
		//	if (aimSprite.getPosition().y > astronautSprt.getPosition().y / 1.5 || mousePosition.y > aimSprite.getPosition().y)
		//	{
		//		// std::cout << "L IF " << mousePosition.x << std::endl;
		//		reachedYDown = false;
		//		aimSprite.setPosition(mousePosition.x, mousePosition.y);
		//	}
		//	else
		//	{
		//		// std::cout << "L ELSE " << mousePosition.x << std::endl;
		//		reachedYDown = true;
		//		// keep sliding perpendiclualry
		//		aimSprite.setPosition(mousePosition.x, aimSprite.getPosition().y);
		//	}
		//}
		// ################
	}

	// border check
	// right/down
	if (astronautSprt.getPosition().x > window.getSize().x)
	{
		astronautSprt.setPosition(0, astronautSprt.getPosition().y); // 0 means the edge 
	}
	if (astronautSprt.getPosition().y > window.getSize().y)
	{
		astronautSprt.setPosition(astronautSprt.getPosition().x, 0);
	}
	// left/up
	if (astronautSprt.getPosition().x < 0)
	{
		astronautSprt.setPosition(window.getSize().x, astronautSprt.getPosition().y);
	}
	if (astronautSprt.getPosition().y < 0)
	{
		astronautSprt.setPosition(astronautSprt.getPosition().x, window.getSize().y);
	}
}

// render
void GameScreen::render(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);


	window.draw(astronautSprt);
	window.draw(aimSprite);
	window.draw(GameScreen::CloseBtnSprite);
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
