#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/b2_body.h>
#include "Entity.h"

class Character : public Entity
{
public:
	Character(b2Body* body);
	bool load(const std::string& tileset, sf::Vector2u tileSize, sf::Vector2u tileScale, int tileNumber);
	void update();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	b2Body* body;
};

