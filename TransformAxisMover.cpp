#include "TransformAxisMover.h"

TransformAxisMover::TransformAxisMover(InputAxis* a, sf::Transformable* t, float s)
{
	transformable = t;
	axis = a;
	speed = s;
}

void TransformAxisMover::update(const sf::Transform& parentTransform)
{
	auto currentPos = transformable->getPosition();
	transformable->setPosition(currentPos.x + speed*axis->xdelta, currentPos.y + speed*axis->ydelta);
}
