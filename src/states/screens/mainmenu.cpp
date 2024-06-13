#include <filesystem>
#include <iostream>
#include "mainmenu.hpp"
// #include "../../Helper/Group.hpp"
// #include "../gameState.hpp"

MainMenu::MainMenu(sf::RenderWindow& window) : GameState(window)
      //window(window),     // Initialize the window reference member
      //mainBackground(),  
      //startBtn()
      //background(mainBackground)
      //startBtnSprite(startBtn)
{
    //loadAssets();
}

// assets
void MainMenu::loadAssets() 
{
    // Textures
    std::filesystem::path absolutePath = std::filesystem::absolute("assets/media/images/space.jpg");
    std::cout << absolutePath << std::endl;
    if (mainBackground.loadFromFile(absolutePath.string()) == false) 
    {
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

    // create button
    std::filesystem::path absolutePath1 = std::filesystem::absolute("assets/media/images/startBtn.png");
    std::cout << absolutePath1 << std::endl;
    if (startBtn.loadFromFile(absolutePath1.string()) == false)
    {
        std::cout << "Loading failed" << std::endl;
        // also add visual error
    }
    else 
    {
        std::cout << "Button texture size: " << startBtn.getSize().x << " x " << startBtn.getSize().y << std::endl;
    }
    startBtn.setSmooth(true); // smoothness
    startBtnSprite.setTexture(startBtn);
    startBtnSprite.setColor(sf::Color(255, 0, 0, 255)); // Red with full opacity
    startBtnSprite.setScale(sf::Vector2f(0.7, 0.7)); // Set the desired scale
    sf::FloatRect bounds2 = startBtnSprite.getLocalBounds();
    startBtnSprite.setOrigin(bounds2.left + bounds2.width / 2.f, bounds2.top + bounds2.height / 2.f);
    startBtnSprite.setPosition(window.getSize().x / 2, window.getSize().y / 2 + 100); // Set final position
}

void MainMenu::handleInput(sf::Event event) {
    // input handling
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
    else if (event.type == sf::Event::KeyPressed) // keyboard
    {
        if (event.key.code == sf::Keyboard::Escape || event.type == sf::Keyboard::Up)
        {
            window.close();
        }
    }
    else if (event.type == sf::Event::MouseButtonPressed) // mouse
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            if (startBtnSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
            {
                std::cout << "Left mouse button was pressed" << std::endl;
                // handle the click
            }
        }
    }
}

void MainMenu::update(sf::Time dt) {
    // logics
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        std::cout << "Up is currently held down" << std::endl; // the up arrow button
    }


    // std::cout << circle.getRotation() << std::endl;
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

void MainMenu::render(sf::RenderWindow& window) {
    // rendering    // rendering
    window.clear(sf::Color::Black);

    window.draw(circle);
    window.draw(startBtnSprite);
    // drawing
    window.display();
}

bool MainMenu::shouldSwitchToGameScreen() const {
    return switchToGameScreen;
}