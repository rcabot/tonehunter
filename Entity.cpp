#include "Entity.h"

void Entity::update()
{
	for (auto c : components) {
		c->update();
	}
}

void Entity::draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const
{
	// combine the parent transform with the node's one
	auto combinedTransform = parentTransform * getTransform();

	// draw its children
	for (auto d : drawables) {
		target.draw(*d, combinedTransform);
	}
}
