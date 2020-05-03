#include "InputAxis.h"
constexpr float LIVE_AXIS_MAX = 1.0f;
constexpr float LIVE_AXIS_MIN = 0.2f;

void InputAxis::update()
{
	xdelta = 0.0f;
	ydelta = 0.0f;

	// first, get keyboard axis, and normalize
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		xdelta -= 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		xdelta += 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		ydelta -= 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		ydelta += 1.0f;
	}
	if (!(xdelta == 0.0f && ydelta == 0.0f)) {

		float mag = sqrt(xdelta * xdelta + ydelta * ydelta);
		xdelta /= mag;
		ydelta /= mag;
	}

	// then, add joystick axis, with dead zone
	if (sf::Joystick::isConnected(0))
	{
		float joystickx = sf::Joystick::getAxisPosition(0, sf::Joystick::X) / 100.0f;
		float joysticky = sf::Joystick::getAxisPosition(0, sf::Joystick::Y) / 100.0f;
		sf::Vector2f deadzoneScaledAxis = getDeadZoneScaledAxis(sf::Vector2f{ joystickx,joysticky });
		xdelta += deadzoneScaledAxis.x;
		ydelta += deadzoneScaledAxis.y;
	}

	// finally, clamp the magnitude of the axis vector
	float mag = getVectorMagnitude(sf::Vector2f{xdelta,ydelta});
	if (mag > 1.0f) {
		xdelta /= mag;
		ydelta /= mag;
	}
}

sf::Vector2f InputAxis::getDeadZoneScaledAxis(const sf::Vector2f& joystickaxis)
{
	float rawMagnitude = getVectorMagnitude(joystickaxis);
	sf::Vector2f normalized = joystickaxis / rawMagnitude;
	float newMag = invLerp(LIVE_AXIS_MIN, LIVE_AXIS_MAX, rawMagnitude);
	if (newMag < 0.0f) {
		return sf::Vector2f{0.0f,0.0f};
	}
	return normalized * newMag;
}

float InputAxis::invLerp(float from, float to, float value) {
	return (value - from) / (to - from);
}

float InputAxis::getVectorMagnitude(const sf::Vector2f& v)
{
	return sqrt(v.x * v.x+ v.y* v.y);
}
