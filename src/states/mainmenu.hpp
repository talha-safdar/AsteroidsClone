#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Helper/Group.hpp"

// to call funs like MainMenu::func();
//namespace MainMenu {
//				void getAssets();
//				void setWindow(sf::RenderWindow window);
//				sf::RenderWindow window;
//}

//class MainMenu {
//public:
//				MainMenu();
//				void getAssets();
//				void logics();
//				void render();
//				sf::RenderWindow& getWindow();
//
//private:
//				sf::RenderWindow window;
//				sf::CircleShape circle;
//};
class MainMenu {
public:
				MainMenu(sf::RenderWindow& window);
				void run();

private:
				sf::RenderWindow& window;
				sf::Texture mainBackground;
				sf::CircleShape circle;
				sf::Sprite background;

				// to separate this logic for button
				sf::Texture startBtn;
				sf::Sprite startBtnSprite;
				//sf::RectangleShape buttonMiddle;
				//sf::CircleShape buttonLeft;
				//sf::CircleShape buttonRight;

				void loadAssets();
				void update();
				void render();
};


