#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../game_state.hpp"

class GameScreen : public GameState {
public:

	GameScreen(sf::RenderWindow& window);

	// GameState interface implementation
	void handleInput(sf::Event event) override;
	void update(sf::Time dt) override;
	void render(sf::RenderWindow& window) override;
	void loadAssets();
	bool shouldSwitchScene() const;
	void resetSwitchToGameScreenFlag() override;
	GameStateType getNextSceneType() const override;

private:
	sf::CircleShape circle;

	sf::Texture aimtexture;
	sf::Sprite aimSprite;
	sf::Texture astronautTxr;
	sf::Sprite astronautSprt;
	sf::Texture lineTexture;
	sf::Sprite lineSprite;

	bool shouldSwitch = false;
	bool isHolding = false;

	bool moveUpTrigger = false;
	bool moveRightTrigger = false;
	bool moveDownTrigger = false;
	bool moveLeftTrigger = false;

	// temporary functions to be moved
	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();
};