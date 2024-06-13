#pragma once

#include <SFML/Graphics.hpp>

// class to manage scenes State design pattern 
class GameState {
public:
				GameState(sf::RenderWindow& window) : window(window) {} // Add this constructor
				virtual void handleInput(sf::Event event) = 0;
				virtual void update(sf::Time dt) = 0;
				virtual void render(sf::RenderWindow& window) = 0;
				virtual void loadAssets() = 0;
protected:
				sf::RenderWindow& window;
};
