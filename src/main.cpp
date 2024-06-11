/*
* Asteroids clone:
* A small game with a spaceship that needs to shoot asteroids and avoid collissions
*/
#include <iostream>
#include <SFML/Graphics.hpp>
#include "states/mainmenu.hpp"

int main()
{
				// WINDOW
				sf::VideoMode desktop = sf::VideoMode::getDesktopMode(); // Get the desktop resolution
				sf::RenderWindow window(sf::VideoMode(1920/2, 1080/2), "Asteroids Clone", sf::Style::None);
				window.setFramerateLimit(60); // manual fps (forced)

				MainMenu mainMenu(window);
				
				while (window.isOpen()) {
								mainMenu.run(); // main menu
				}
				return 0;
}

