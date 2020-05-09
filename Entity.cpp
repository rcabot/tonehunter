#include "Entity.h"

void Entity::update(const sf::Transform& parentTransform)
{
	auto combinedTransform = parentTransform * getTransform();
	
	// update all it's components
	for (auto c : components) {
		c->update(combinedTransform);
	}
	
	// update it's children
	for (auto c : children) {
		c->update(combinedTransform);
	}
}

void Entity::draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const
{
	// combine the parent transform with the node's one
	auto combinedTransform = parentTransform * getTransform();

	// draw its drawables
	for (auto d : drawables) {
		target.draw(*d, combinedTransform);
	}

	// draw it's children
	for (auto c : children) {
		c->draw(target, combinedTransform);
	}
}
