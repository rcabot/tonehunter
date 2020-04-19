#pragma once
#include "Component.h"
#include <vector>
#include "SFML/Graphics.hpp"
class Entity : public sf::Drawable, public sf::Transformable
{
public:
	virtual void update();
	std::vector<Component*> components;
	std::vector<Drawable*> drawables;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

