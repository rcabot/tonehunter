#include "Entity.h"

void Entity::update()
{
	for (auto c : components) {
		c->update();
	}
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto d : drawables) {
		target.draw(*d,states);
	}
}
