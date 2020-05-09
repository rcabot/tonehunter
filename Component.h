#pragma once

#include "SFML/Graphics.hpp"
class Component
{
public:
	virtual void update(const sf::Transform& parentTransform)=0;
};

