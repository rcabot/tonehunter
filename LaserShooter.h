#pragma once


#include "InputAxis.h"
#include "BoxTriggerZone.h"
#include "SpriteSheetSpriteRenderer.h"
#include "Entity.h"

class LaserShooter : public Component
{
public:
	LaserShooter(InputAxis* axis, BoxTriggerZone* hitbox, SpriteSheetSpriteRenderer* renderer, Entity* entity);
	void update(const sf::Transform& parentTransform);
private:
	InputAxis* axis;
	BoxTriggerZone* hitbox;
	SpriteSheetSpriteRenderer* renderer; 
	Entity* entity;
};

