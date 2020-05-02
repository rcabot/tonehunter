#include "Collider.h"
#include "ColliderWorld.h"
Collider::Collider()
{
	getWorld()->colliders.emplace_back(this);
}
Collider::~Collider()
{
	//todo!
	//getWorld().components.(this);
}
bool Collider::compareBoxExtents(const BoxExtents& a, const BoxExtents& b)
{
	bool x_overlaps = (a.left < b.right) && (a.right > b.left);
	bool y_overlaps = (a.top < b.bottom) && (a.bottom > b.top);
	return x_overlaps&& y_overlaps;
}
ColliderWorld* Collider::world_ = new ColliderWorld;