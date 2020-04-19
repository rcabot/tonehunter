#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>
class InputAxis : public Component
{
public:
	void update();
	float xdelta;
	float ydelta;
};

