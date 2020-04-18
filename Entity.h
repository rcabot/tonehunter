#pragma once
#include "Component.h"
#include <vector>
#include "SFML/Graphics.hpp"
class Entity : public sf::Drawable, public sf::Transformable
{
public:
	virtual void update();
private:
	std::vector<Component*> components;
};

