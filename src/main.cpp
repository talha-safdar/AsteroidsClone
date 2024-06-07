/*
* Asteroids clone:
* A small game with a spaceship that needs to shoot asteroids and avoid collissions
*/
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
				// WINDOW
				sf::VideoMode desktop = sf::VideoMode::getDesktopMode(); // Get the desktop resolution
				sf::RenderWindow window(desktop, "Asteroids Clone", sf::Style::Fullscreen);

				while (window.isOpen())
				{
								sf::Event event;
								while (window.pollEvent(event))
								{
												if (event.type == sf::Event::Closed) 
												{
																window.close();
												}
												else if (event.type == sf::Event::KeyPressed) 
												{
																if (event.key.code == sf::Keyboard::Escape || event.type == sf::Keyboard::Up)
																{
																				window.close();
																}
												}
								}

								// LOGIC
								// press
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
								{
												std::cout << "Up is currently held down" << std::endl; // the up arrow button
								}

								// RENDERING
								window.clear(sf::Color(0, 0, 0));

								// DRAWING

								window.display();
				}
				return 0;
}

