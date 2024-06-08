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
				//sf::RenderWindow window(sf::VideoMode(1920/2, 1080/2), "Asteroids Clone", sf::Style::Default);
				MainMenu mm;

				//window.setFramerateLimit(60); // manual fps (forced)

				mm.getAssets();
				//// Textures
				//sf::Texture mainBackground;
				//if (mainBackground.loadFromFile("assets/media/images/space.jpg") == false) {
				//				std::cout << "Loading failed" << std::endl;
				//				// also add visual error
				//}
				//mainBackground.setSmooth(true); // smoothness



				// std::cout << "x: " << window.getSize().x << std::endl;

				//// Circle for background
				//sf::CircleShape circle(window.getSize().x / 2 + 100, 30);
				//circle.setRadius(window.getSize().x / 2 + 100);
				//sf::FloatRect bounds = circle.getLocalBounds(); // very useful to get local size (left, top, width, height)
				//circle.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
				//circle.setPosition(window.getSize().x / 2, window.getSize().y / 2);
				//circle.setTexture(&mainBackground);

				//// Sprite
				//sf::Sprite background;
				//background.setTexture(mainBackground);

				//// set origin to the centre of the original image
				//sf::FloatRect localBounds = background.getGlobalBounds();
				//background.setOrigin(localBounds.width / 2.f, localBounds.height / 2.f);

				//// scale to fit the window
				//background.setScale(
				//				mm.getWindow().getSize().x / localBounds.width,
				//				mm.getWindow().getSize().y / localBounds.height
				//);

				//// set position to the centre of the window
				//sf::Vector2u windowSize = mm.getWindow().getSize();
				//background.setPosition(windowSize.x / 2.f, windowSize.y / 2.f);


				while (mm.getWindow().isOpen())
				{
								sf::Event event;
								while (mm.getWindow().pollEvent(event))
								{
												if (event.type == sf::Event::Closed) 
												{
																mm.getWindow().close();
												}
												else if (event.type == sf::Event::KeyPressed) 
												{
																if (event.key.code == sf::Keyboard::Escape || event.type == sf::Keyboard::Up)
																{
																				mm.getWindow().close();
																}
												}
								}

								// LOGIC
								// press
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
								{
												std::cout << "Up is currently held down" << std::endl; // the up arrow button
								}

								// circle.rotate(-0.17f);

								// std::cout << "scaling: " << circle.getRotation() << std::endl;

								//if (circle.getRotation() > (360 / 4) * 2) // more than 180
								//{
								//				//circle.scale(1.0009f, 1.0009f);
								//				circle.scale(1.001f, 1.001f);
								//}
								//else if (circle.getRotation() < (360 / 4) * 2)
								//{
								//				circle.scale(0.9991f, 0.9991f);
								//}


								mm.render();
								//// RENDERING
								//mm.getWindow().clear(sf::Color(0, 0, 0));
								//mm.getWindow().draw(circle);


								//// DRAWING

								//mm.getWindow().display();
				}
				return 0;
}

