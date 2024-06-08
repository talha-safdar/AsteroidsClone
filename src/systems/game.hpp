#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

//namespace MySystem {
//				void getWindow();
//}

class Game {
public:
				Game();
				void run();

private:
				sf::RenderWindow window;
};