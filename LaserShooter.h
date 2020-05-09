#pragma once


#include "InputAxis.h"
#include "BoxTriggerZone.h"
#include "SpriteSheetSpriteRenderer.h"

class LaserShooter : public Component
{
public:
	LaserShooter(InputAxis* axis, BoxTriggerZone* hitbox, SpriteSheetSpriteRenderer* renderer);
	void update(const sf::Transform& parentTransform);
private:
	InputAxis* axis;
	BoxTriggerZone* hitbox;
	SpriteSheetSpriteRenderer* renderer;
};

