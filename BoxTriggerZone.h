#pragma once

#include "Collider.h"

class BoxTriggerZone : public Collider
{
	void update(const sf::Transform& parentTransform);
};

