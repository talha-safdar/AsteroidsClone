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
				sf::RenderWindow window(sf::VideoMode(1920/2, 1080/2), "Asteroids Clone", sf::Style::Default);
				window.setFramerateLimit(60); // manual fps (forced)
				// Textures
				sf::Texture mainBackground;
				if (mainBackground.loadFromFile("data/media/images/space2.jpg") == false) {
								std::cout << "Loading failed" << std::endl;
								// also add visual error
				}
				mainBackground.setSmooth(true); // smoothness

				// Sprite
				sf::Sprite background;
				background.setTexture(mainBackground);

				// set origin to the centre of the original image
				sf::FloatRect localBounds = background.getGlobalBounds();
				background.setOrigin(localBounds.width / 2.f, localBounds.height / 2.f);

				// scale to fit the window
				background.setScale(
								window.getSize().x / localBounds.width,
								window.getSize().y / localBounds.height
				);

				// set position to the centre of the window
				sf::Vector2u windowSize = window.getSize();
				background.setPosition(windowSize.x / 2.f, windowSize.y / 2.f);


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

								background.rotate(-0.03f);

								std::cout << "Rotation: " << background.getRotation() << std::endl;

								if (background.getRotation() > (360 / 4) * 3) // more than 270
								{
												background.scale(1.0009f, 1.0009f);
								}
								else if (background.getRotation() < (360 / 4) * 3 && background.getRotation() > (360 / 4) * 2)
								{
												background.scale(0.9991f, 0.9991f);
								}
								else if (background.getRotation() < (360 / 4) * 2 && background.getRotation() > (360 / 4) * 1)
								{
												background.scale(1.0015f, 1.0015f);
								}



								// RENDERING
								window.clear(sf::Color(0, 0, 0));
								window.draw(background);



								// DRAWING

								window.display();
				}
				return 0;
}

