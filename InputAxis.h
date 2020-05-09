#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>
class InputAxis : public Component
{
public:
	void update(const sf::Transform& parentTransform);
	float xdelta;
	float ydelta;
	float getCurrentDeltaMagnitude();
	sf::Vector2f getCurrentAsVector2f();
private:
	sf::Vector2f getDeadZoneScaledAxis(const sf::Vector2f& joystickaxis);
	float invLerp(float from, float to, float value);
	float getVectorMagnitude(const sf::Vector2f& v);
};

