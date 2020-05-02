#include "DynamicBoxCollider.h"
#include <iostream>
#include "ColliderWorld.h"

DynamicBoxCollider::DynamicBoxCollider(float h, float w, sf::Transformable* t) : Collider()
{
	height = h;
	width = w;
	transformable = t;
}

DynamicBoxCollider::~DynamicBoxCollider() 
{
	Collider::~Collider();
}

void DynamicBoxCollider::update()
{
	auto world = getWorld();
	for (auto c : world->colliders)
	{
		if (detectCollision(c)) {
			respondToCollision(c); // eventually, might want to aggregate the responses to multiple collisions
			return;
		}
	}
}

bool DynamicBoxCollider::detectCollision(Collider* other)
{
	return other->detectCollisionAgainstBox(getExtents());
}

void DynamicBoxCollider::respondToCollision(Collider* other)
{
	//std::cout << "!";
}

BoxExtents DynamicBoxCollider::getExtents()
{
	BoxExtents extents;
	auto pos = transformable->getPosition();
	extents.left = pos.x-width/2.0f;
	extents.right = pos.x + width / 2.0f;
	extents.top = pos.y - height / 2.0f;
	extents.bottom = pos.y + height / 2.0f;
	return extents;
}
