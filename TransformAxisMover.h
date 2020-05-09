#pragma once
#include "Component.h"
#include "SFML/Graphics.hpp"
#include "InputAxis.h"
class TransformAxisMover : public Component
{
public:
	TransformAxisMover(InputAxis* a, sf::Transformable* t, float s);
	void update(const sf::Transform& parentTransform);
	sf::Transformable* transformable;
	InputAxis* axis;
	float speed;
};

