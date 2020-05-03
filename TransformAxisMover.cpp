#include "TransformAxisMover.h"

TransformAxisMover::TransformAxisMover(InputAxis* a, sf::Transformable* t)
{
	transformable = t;
	axis = a;
}

void TransformAxisMover::update()
{
	auto currentPos = transformable->getPosition();
	transformable->setPosition(currentPos.x + axis->xdelta, currentPos.y + axis->ydelta);
}
