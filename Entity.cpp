#include "Entity.h"

void Entity::update()
{
	for (auto c : components) {
		c->update();
	}
}
