#pragma once
#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "SFML/Graphics.hpp"
#include "Entity.h"

class TileMap : public Entity
{
public:

	bool load(const std::string& tileset, sf::Vector2u tileSize, sf::Vector2u tileScale,
		const int* tiles, unsigned int width, unsigned int height);

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};

