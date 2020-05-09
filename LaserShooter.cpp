#include "LaserShooter.h"

LaserShooter::LaserShooter(InputAxis* a, BoxTriggerZone* h, SpriteSheetSpriteRenderer* r)
{
	axis = a;
	hitbox = h;
	renderer = r;
}

void LaserShooter::update(const sf::Transform& parentTransform)
{

}
