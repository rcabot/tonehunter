#include "InputAxis.h"
constexpr float LIVE_AXIS_MAX = 1.0f;
constexpr float LIVE_AXIS_MIN = 0.2f;

InputAxis::InputAxis(unsigned int a,
	sf::Joystick::Axis x,
	sf::Joystick::Axis y)
{
	joystickIndex = a;
	xdelta = 0.0f;
	ydelta = 0.0f;
	xAxis = x;
	yAxis = y;
	leftKey = mapKey(sf::Keyboard::Left,xAxis,yAxis);
	rightKey = mapKey(sf::Keyboard::Right, xAxis, yAxis);
	upKey = mapKey(sf::Keyboard::Up, xAxis, yAxis);
	downKey = mapKey(sf::Keyboard::Down, xAxis, yAxis);
}

void InputAxis::update(const sf::Transform& parentTransform)
{
	xdelta = 0.0f;
	ydelta = 0.0f;

	// first, get keyboard axis, and normalize
	if (sf::Keyboard::isKeyPressed(leftKey))
	{
		xdelta -= 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(rightKey))
	{
		xdelta += 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(upKey))
	{
		ydelta -= 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(downKey))
	{
		ydelta += 1.0f;
	}
	if (!(xdelta == 0.0f && ydelta == 0.0f)) {

		float mag = sqrt(xdelta * xdelta + ydelta * ydelta);
		xdelta /= mag;
		ydelta /= mag;
	}

	// then, add joystick axis, with dead zone
	if (sf::Joystick::isConnected(joystickIndex))
	{
		float joystickx = sf::Joystick::getAxisPosition(joystickIndex, xAxis) / 100.0f;
		float joysticky = sf::Joystick::getAxisPosition(joystickIndex, yAxis) / 100.0f;
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

float InputAxis::getCurrentDeltaMagnitude()
{
	return getVectorMagnitude(sf::Vector2f(xdelta,ydelta));
}

sf::Vector2f InputAxis::getCurrentAsVector2f()
{
	return sf::Vector2f(xdelta,ydelta);
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

sf::Keyboard::Key InputAxis::mapKey(sf::Keyboard::Key key,sf::Joystick::Axis xax, sf::Joystick::Axis yax)
{
	switch (key)
	{
    case sf::Keyboard::Left:
		if (xax == sf::Joystick::X) return sf::Keyboard::A;
    case sf::Keyboard::Right:
		if (xax == sf::Joystick::X) return sf::Keyboard::D;
    case sf::Keyboard::Up:
		if (yax == sf::Joystick::Y) return sf::Keyboard::W;
    case sf::Keyboard::Down:
		if (yax == sf::Joystick::Y) return sf::Keyboard::S;
    default:
		return key;
	}
}
