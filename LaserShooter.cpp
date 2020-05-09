#include "LaserShooter.h"
#include <iostream>

LaserShooter::LaserShooter(InputAxis* a, BoxTriggerZone* h, SpriteSheetSpriteRenderer* r,sf::Transformable* t)
{
	axis = a;
	hitbox = h;
	renderer = r;
	transformable = t;
}

void LaserShooter::update(const sf::Transform& parentTransform)
{
	renderer->active = (axis->getCurrentDeltaMagnitude() != 0.0f);
	transformable->setPosition(axis->getCurrentAsVector2f()*20.0f);
}
