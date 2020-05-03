#include "DynamicBoxCollider.h"
#include <iostream>
#include "ColliderWorld.h"

DynamicBoxCollider::DynamicBoxCollider(float h, float w, sf::Transformable* t) : Collider()
{
	height = h;
	width = w;
	transformable = t;
	previousTransformablePosition = transformable->getPosition();
}

DynamicBoxCollider::~DynamicBoxCollider() 
{
	Collider::~Collider();
}

// checks and corrects axis separately. this works because surface normals 
// are only ever along the axis (because all is tile based.)
void DynamicBoxCollider::update()
{
	auto world = getWorld();

	// reset position to just the movement with x
	auto newPosition = transformable->getPosition();
	auto delta = newPosition - previousTransformablePosition;
	transformable->setPosition(previousTransformablePosition + sf::Vector2f{delta.x,0.0f});

	// check and correct x delta
	for (auto c : world->colliders)
	{
		if (detectCollision(c)) {
			// eventually, might want to aggregate the responses to multiple collisions
			transformable->setPosition(previousTransformablePosition);
			break;
		}
	}
	previousTransformablePosition = transformable->getPosition();

	// reset position to just the movement with y
	transformable->setPosition(previousTransformablePosition + sf::Vector2f{ 0.0f,delta.y });

	// check and correct y delta
	for (auto c : world->colliders)
	{
		if (detectCollision(c)) {
			// eventually, might want to aggregate the responses to multiple collisions
			transformable->setPosition(previousTransformablePosition);
			break;
		}
	}

	previousTransformablePosition = transformable->getPosition();
}

bool DynamicBoxCollider::detectCollision(Collider* other, float offsetX, float offsetY)
{
	return other->detectCollisionAgainstBox(getExtents(offsetX,offsetY));
}

bool DynamicBoxCollider::detectCollision(Collider* other)
{
	return other->detectCollisionAgainstBox(getExtents());
}

BoxExtents DynamicBoxCollider::getExtents(float offsetX, float offsetY)
{
	BoxExtents extents;
	auto pos = transformable->getPosition() + sf::Vector2f{offsetX,offsetY};
	extents.left = pos.x;
	extents.right = pos.x + width;
	extents.top = pos.y;
	extents.bottom = pos.y + height;
	return extents;
}

BoxExtents DynamicBoxCollider::getExtents()
{
	return getExtents(0.0f, 0.0f);
}
