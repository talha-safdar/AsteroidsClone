#include "Group.hpp"

void Group::addChild(sf::Drawable& child)
{
	children.push_back(&child);
}

// can add more funcions
/*
* remove
* clear
* get count or get children
* conrains
*/

void Group::draw(sf::RenderTarget& target, sf::RenderStates states) {
	states.transform *= getTransform();
	for (const auto& child : children) {
		target.draw(*child, states);
	}
}