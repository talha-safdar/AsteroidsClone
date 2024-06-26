#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../game_state.hpp"

class GameScreen : public GameState {
public:
    GameScreen(sf::RenderWindow& window);

    // GameState interface implementation
    void handleInput(sf::Event event) override;
    void update(sf::Time dt) override;
    void render(sf::RenderWindow& window) override;
    void loadAssets();
    bool shouldSwitchScene() const;
    void resetSwitchToGameScreenFlag() override;
    GameStateType getNextSceneType() const override;

private:
    //sf::Texture mainBackground;
    sf::CircleShape circle;
    //sf::Sprite background;
    //sf::RectangleShape rect;
    //sf::Texture startBtn;
    //sf::Sprite startBtnSprite;
    bool shouldSwitch = false;
				bool isHolding = false;
				sf::Texture astronautTxr;
				sf::Sprite astronautSprt;
				bool moveUp = false;
				bool moveRight = false;
				bool moveDown = false;
				bool moveLeft = false;
};