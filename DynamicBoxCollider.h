#pragma once
#include "Collider.h"
#include "StaticTileMapCollider.h"
#include "BoxExtents.h"
#include "SFML/Graphics.hpp"
#include <memory>

class DynamicBoxCollider : public Collider
{
public:
	DynamicBoxCollider(float h, float w, sf::Transformable* t);
	~DynamicBoxCollider();
	void update();
	sf::Transformable* transformable;
private:
	bool detectCollision(Collider* other, float offsetX, float offsetY);
	bool detectCollision(Collider* other);
	BoxExtents getExtents();
	BoxExtents getExtents(float offsetX, float offsetY);

	sf::Vector2f previousTransformablePosition;
	float width;
	float height;
};

