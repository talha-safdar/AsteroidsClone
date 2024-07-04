#include <iostream>
#include <filesystem>
#include "game_state.hpp"

//GameState::GameState(sf::RenderWindow& window) : window(window) {
//
//}

void GameState::addCloseButton()
{
	// texture
	std::filesystem::path absolutePath = std::filesystem::absolute("assets/media/images/cancel.png");
	if (CloseBtnTexture.loadFromFile(absolutePath.string()) == false)
	{
		std::cout << "Loading failed" << std::endl;
		// also add visual error
	}
	CloseBtnTexture.setSmooth(true);

	// sprite
	CloseBtnSprite.setTexture(CloseBtnTexture);
	CloseBtnSprite.setPosition(920, 15);
	CloseBtnSprite.setScale(0.05, 0.05);
}
