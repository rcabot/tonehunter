#include "LaserShooter.h"
#include <iostream>

LaserShooter::LaserShooter(InputAxis* a, BoxTriggerZone* h, SpriteSheetSpriteRenderer* r,Entity* e)
{
	axis = a;
	hitbox = h;
	renderer = r;
	entity = e;
}

void LaserShooter::update(const sf::Transform& parentTransform)
{
	renderer->active = (axis->getCurrentDeltaMagnitude() != 0.0f);
	entity->setPosition(axis->getCurrentAsVector2f()*20.0f);
}
