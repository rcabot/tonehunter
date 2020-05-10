#pragma once
#include "Component.h"
#include <vector>
#include "SFML/Graphics.hpp"
class Entity : public sf::Transformable
{
public:
	virtual void update(const sf::Transform& parentTransform);
	std::vector<Component*> components;
	std::vector<sf::Drawable*> drawables;
	std::vector<Entity*> children;
	virtual void draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const;
	bool active = true;
private:
};

