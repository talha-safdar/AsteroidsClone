#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
//#include "../../Helper/Group.hpp"
#include "../gameState.hpp"

class MainMenu : public GameState {
public:
    MainMenu(sf::RenderWindow& window);

    // GameState interface implementation
    void handleInput(sf::Event event) override;
    void update(sf::Time dt) override;
    void render(sf::RenderWindow& window) override;
    void loadAssets();
    bool shouldSwitchToGameScreen() const;
    // void resetSwitchToGameScreenFlag();

private:
    sf::Texture mainBackground;
    sf::CircleShape circle;
    sf::Sprite background;
    sf::RectangleShape rect;
    sf::Texture startBtn;
    sf::Sprite startBtnSprite;

    bool switchToGameScreen = false;


};

//class MainMenu : public GameState {
//public:
//				MainMenu(sf::RenderWindow& window);
//
//				// GameState interface implementation:
//				void handleInput(sf::Event event) override;
//				void update(sf::Time dt) override;
//				void render(sf::RenderWindow& window) override;
//				// void run();
//
//				bool shouldSwitchToGameScreen() const { return switchToGameScreen; } // Add this method
//
//private:
//				sf::RenderWindow& window;
//				sf::Texture mainBackground;
//				sf::CircleShape circle;
//				sf::Sprite background; // might not need this
//
//				// to separate this logic for button
//				sf::Texture startBtn;
//				sf::Sprite startBtnSprite;
//				bool switchToGameScreen = false; // Flag to indicate scene switch
//
//				//sf::RectangleShape buttonMiddle;
//				//sf::CircleShape buttonLeft;
//				//sf::CircleShape buttonRight;
//
//				void loadAssets();
//				// void update();
//				void render();
//};


