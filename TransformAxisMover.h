#pragma once
#include "Component.h"
#include "SFML/Graphics.hpp"
#include "InputAxis.h"
class TransformAxisMover : public Component
{
public:
	TransformAxisMover(InputAxis*, sf::Transformable*);
	void update();
	sf::Transformable* transformable;
	InputAxis* axis;
};

