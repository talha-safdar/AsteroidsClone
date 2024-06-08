#include "mainmenu.hpp"

//void MainMenu::getAssets()

MainMenu::MainMenu() : window(sf::VideoMode(1920 / 2, 1080 / 2), "Asteroids Clone", sf::Style::Default) {}

void MainMenu::getAssets() {
				// Textures
				sf::Texture mainBackground;
				if (mainBackground.loadFromFile("../assets/media/images/space.jpg") == false) {
								std::cout << "Loading failed" << std::endl;
								// also add visual error
				}
				mainBackground.setSmooth(true); // smoothness

				// Circle for background
				sf::CircleShape circle(window.getSize().x / 2 + 100, 30);
				circle.setRadius(window.getSize().x / 2 + 100);
				sf::FloatRect bounds = circle.getLocalBounds(); // very useful to get local size (left, top, width, height)
				circle.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
				circle.setPosition(window.getSize().x / 2, window.getSize().y / 2);
				circle.setTexture(&mainBackground);

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
}

void MainMenu::logics() {
				circle.rotate(-0.17f);
				if (circle.getRotation() > (360 / 4) * 2) // more than 180
				{
								//circle.scale(1.0009f, 1.0009f);
								circle.scale(1.001f, 1.001f);
				}
				else if (circle.getRotation() < (360 / 4) * 2)
				{
								circle.scale(0.9991f, 0.9991f);
				}

}

void MainMenu::render() {
				// RENDERING
				window.clear(sf::Color(0, 0, 0));
				window.draw(circle);


				// DRAWING

				window.display();
}

sf::RenderWindow& MainMenu::getWindow() {
				return window;
}



