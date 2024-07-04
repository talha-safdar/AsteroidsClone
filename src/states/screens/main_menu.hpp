#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../game_state.hpp"

class MainMenu : public GameState 
{
public:
	MainMenu(sf::RenderWindow& window);

	// GameState interface implementation
	void handleInput(sf::Event event) override;
	void update(sf::Time dt) override;
	void render(sf::RenderWindow& window) override;
	void loadAssets();
	bool shouldSwitchScene() const override;
	void resetSwitchToGameScreenFlag() override;
	GameStateType getNextSceneType() const override;
	~MainMenu() {};

private:
	sf::Texture mainBackground;
	sf::CircleShape circle;
	sf::Sprite background;
	sf::RectangleShape rect;
	sf::Texture startBtn;
	sf::Sprite startBtnSprite;
	bool shouldSwitch = false;
};