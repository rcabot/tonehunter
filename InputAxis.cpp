#include "InputAxis.h"

void InputAxis::update()
{
	xdelta = 0.0f;
	ydelta = 0.0f;
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
	if (xdelta == 0.0f && ydelta == 0.0f) return;
	float mag = sqrt(xdelta * xdelta + ydelta * ydelta);
	xdelta /= mag;
	ydelta /= mag;
}
