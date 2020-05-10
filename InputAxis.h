#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>
class InputAxis : public Component
{
public:
	InputAxis(unsigned int axisIndex,sf::Joystick::Axis xAxis,sf::Joystick::Axis yAxis);
	void update(const sf::Transform& parentTransform);
	float xdelta;
	float ydelta;
	float getCurrentDeltaMagnitude();
	sf::Vector2f getCurrentAsVector2f();
	unsigned int joystickIndex;
private:
	sf::Vector2f getDeadZoneScaledAxis(const sf::Vector2f& joystickaxis);
	float invLerp(float from, float to, float value);
	float getVectorMagnitude(const sf::Vector2f& v);
	sf::Keyboard::Key mapKey(sf::Keyboard::Key key, sf::Joystick::Axis xax, sf::Joystick::Axis yax);
	sf::Joystick::Axis xAxis;
	sf::Joystick::Axis yAxis;
	sf::Keyboard::Key leftKey;
	sf::Keyboard::Key rightKey;
	sf::Keyboard::Key upKey;
	sf::Keyboard::Key downKey;
};

