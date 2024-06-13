/*
* Asteroids clone:
* A small game with a spaceship that needs to shoot asteroids and avoid collissions
*/
#include <iostream>
#include <SFML/Graphics.hpp>
#include "states/gameState.hpp"
#include "states/screens/mainmenu.hpp"

int main()
{
				// WINDOW
				sf::VideoMode desktop = sf::VideoMode::getDesktopMode(); // Get the desktop resolution
				sf::RenderWindow window(sf::VideoMode(1920/2, 1080/2), "Asteroids Clone", sf::Style::None);
				window.setFramerateLimit(60); // manual fps (forced)

				MainMenu mainMenu(window);
				std::unique_ptr<GameState> currentScene = std::make_unique<MainMenu>(window);
				currentScene->loadAssets();
				// std::unique_ptr<GameState> currentScene = std::make_unique < MainMenu();

				sf::Clock clock;

				while (window.isOpen()) {
								sf::Event event;
								while (window.pollEvent(event)) {
												currentScene->handleInput(event);
								}
								sf::Time deltaTime = clock.restart();
								currentScene->update(deltaTime);
								currentScene->render(window);
				}
				return 0;
}

