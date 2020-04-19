#pragma once
#include "Component.h"
#include <vector>
#include "SFML/Graphics.hpp"
class Entity : public sf::Transformable
{
public:
	virtual void update();
	std::vector<Component*> components;
	std::vector<sf::Drawable*> drawables;
	virtual void draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const;
private:
};

