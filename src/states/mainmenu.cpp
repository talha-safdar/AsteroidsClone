#include "mainmenu.hpp"

#include <filesystem>
//void MainMenu::getAssets()

//ainMenu::MainMenu() : window(sf::VideoMode(1920 / 2, 1080 / 2), "Asteroids Clone", sf::Style::Default) {}

//void MainMenu::getAssets() {
//				// Textures
//				sf::Texture mainBackground;
//				std::filesystem::path absolutePath = std::filesystem::absolute("assets/media/images/space2.jpg");
//				std::cout << absolutePath << std::endl;
//				if (mainBackground.loadFromFile(absolutePath.string()) == false) {
//								std::cout << "Loading failed" << std::endl;
//								// also add visual error
//				}
//				mainBackground.setSmooth(true); // smoothness
//
//				// Circle for background
//				sf::CircleShape circle(window.getSize().x / 2 + 100, 30);
//				circle.setRadius(window.getSize().x / 2 + 100);
//				sf::FloatRect bounds = circle.getLocalBounds(); // very useful to get local size (left, top, width, height)
//				circle.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
//				circle.setPosition(window.getSize().x / 2, window.getSize().y / 2);
//				circle.setTexture(&mainBackground);
//
//				// Sprite
//				sf::Sprite background;
//				background.setTexture(mainBackground);
//
//				// set origin to the centre of the original image
//				sf::FloatRect localBounds = background.getGlobalBounds();
//				background.setOrigin(localBounds.width / 2.f, localBounds.height / 2.f);
//
//				// scale to fit the window
//				background.setScale(
//								window.getSize().x / localBounds.width,
//								window.getSize().y / localBounds.height
//				);
//
//				// set position to the centre of the window
//				sf::Vector2u windowSize = window.getSize();
//				background.setPosition(windowSize.x / 2.f, windowSize.y / 2.f);
//}
//
//void MainMenu::logics() {
//				std::cout << circle.getRotation() << std::endl;
//				circle.rotate(-0.17f);
//				if (circle.getRotation() > (360 / 4) * 2) // more than 180
//				{
//								//circle.scale(1.0009f, 1.0009f);
//								circle.scale(1.001f, 1.001f);
//				}
//				else if (circle.getRotation() < (360 / 4) * 2)
//				{
//								circle.scale(0.9991f, 0.9991f);
//				}
//
//}
//
//void MainMenu::render() {
//				// RENDERING
//				
//				window.draw(circle);
//
//
//				// DRAWING
//
//
//}
//
//sf::RenderWindow& MainMenu::getWindow() {
//				return window;
//}


MainMenu::MainMenu(sf::RenderWindow& window) : window(window) {
    loadAssets();
}

// assets
void MainMenu::loadAssets() {
    // Textures
    std::filesystem::path absolutePath = std::filesystem::absolute("assets/media/images/space.jpg");
    std::cout << absolutePath << std::endl;
    if (mainBackground.loadFromFile(absolutePath.string()) == false) {
        std::cout << "Loading failed" << std::endl;
        // also add visual error
    }
    mainBackground.setSmooth(true); // smoothness

    // Circle for background
    circle.setRadius(window.getSize().x / 2 + 100);
    circle.setPointCount(30);
    circle.setRadius(window.getSize().x / 2 + 100);
    sf::FloatRect bounds = circle.getLocalBounds(); // very useful to get local size (left, top, width, height)
    circle.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    //circle.setPosition(window.getSize().x / 2, window.getSize().y / 2);
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

// input handling
void MainMenu::run() {
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
        update();
        render();
    }
}

// logics
void MainMenu::update() {
    // LOGIC
    // press
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        std::cout << "Up is currently held down" << std::endl; // the up arrow button
    }


    std::cout << circle.getRotation() << std::endl;
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

// render
void MainMenu::render() {
    window.clear(sf::Color::Black);

    window.draw(circle);

    window.display();
}
