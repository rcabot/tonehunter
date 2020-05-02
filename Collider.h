#pragma once
#include "Component.h"
#include "BoxExtents.h"

class ColliderWorld;
class Collider : public Component
{
public:
	Collider();
	virtual ~Collider();
	virtual void update() {};
	virtual bool detectCollisionAgainstBox(const BoxExtents& a) { return false; };
protected:
	ColliderWorld* getWorld() { return world_; }
	bool compareBoxExtents(const BoxExtents& a, const BoxExtents& b);
private:
	static ColliderWorld* world_;
};

