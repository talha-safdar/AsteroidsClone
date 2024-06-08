#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Group : public sf::Drawable, public sf::Transformable 
{
public:
				void addChild(sf::Drawable& child);
				void removeChild(sf::Drawable& child);

private:
				virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
				std::vector<sf::Drawable*> children;
};