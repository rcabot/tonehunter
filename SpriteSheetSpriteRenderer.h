#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class SpriteSheetSpriteRenderer : public sf::Drawable, public sf::Transformable
{
public:
	bool load(const std::string& tileset, sf::Vector2u tileSize, sf::Vector2u tileScale, int tileNumber);
	bool active;
private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	sf::VertexArray vertices;
	sf::Texture tileset;
};

