#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>
class InputAxis : public Component
{
public:
	void update();
	float xdelta;
	float ydelta;
private:
	sf::Vector2f getDeadZoneScaledAxis(const sf::Vector2f& joystickaxis);
	float invLerp(float from, float to, float value);
	float getVectorMagnitude(const sf::Vector2f& v);
};

