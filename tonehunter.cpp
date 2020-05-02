#include <iostream>
#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"
#include "TileMap.h"
#include "Character.h"
#include "tonehunter.h"
#include "Entity.h"
#include "Level.h"
#include "InputAxis.h"
#include "TransformAxisMover.h"
#include "DynamicBoxCollider.h"
#include "StaticTileMapCollider.h"

int main()
{
	const float FPS = 60.0f; //The desired FPS. (The number of updates each second).
	//PlatformHelper platform;
	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	//float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	float screenScalingFactor = 1.0f;

	auto windowTiles = sf::Vector2u(8, 8);
	auto tileSize = sf::Vector2u(8, 8);
	auto tileScale = sf::Vector2u(4, 4);
	window.create(sf::VideoMode(
		windowTiles.x * tileSize.x * tileScale.x * screenScalingFactor,
		windowTiles.y * tileSize.y * tileScale.y * screenScalingFactor),
		"Rachel's very special game!");
	window.setFramerateLimit(FPS);
	std::vector<std::unique_ptr<Entity>> entities;


	b2Vec2 gravity(0.0f, 0.0f);
	b2World world(gravity);

	//platform.setIcon(window.getSystemHandle());

	// create level
	const int levelBitmap[] =
	{
		 0, 1, 1, 1, 1, 1, 1, 3,
	    10,11,11,11,11,11,11,13,
		10,11,11,11,11,11,11,13,
		10,11,11,11,11,11,11,13,
		10,11,11,11,11,11,11,13,
		10,11,11,11,11,11,11,13,
		10,11,11,11,11,11,11,13,
		20, 1, 1, 1, 1, 1, 1,23,
	};
	auto tileMapRenderer = new TileMap;
	if (!tileMapRenderer->load(
		"content/colored_tilemap_packed.png", 
		tileSize,
		tileScale, 
		levelBitmap, windowTiles.x, windowTiles.y)) {
		return -1;
	}
	auto level = new Level;
	auto staticTileMapCollider = new StaticTileMapCollider(
		levelBitmap, 
		windowTiles.x, 
		windowTiles.y, 
		tileSize.x * tileScale.x, 
		tileSize.y * tileScale.y);
	level->drawables.emplace_back(tileMapRenderer);
	level->components.emplace_back(staticTileMapCollider);

	// create character
	auto character = new Character;
	auto inputAxis = new InputAxis;
	auto mover = new TransformAxisMover(inputAxis,character);
	auto dynamicBoxCollider = new DynamicBoxCollider(
		tileSize.x * tileScale.x,
		tileSize.y * tileScale.y,
		character);
	auto characterSpriteRenderer = new SpriteSheetSpriteRenderer;
	if (!characterSpriteRenderer->load(
		"content/colored_tilemap_packed.png", 
		tileSize,
		tileScale, 7)) {
		return -1;
	}
	character->drawables.emplace_back(characterSpriteRenderer);
	character->components.emplace_back(inputAxis);
	character->components.emplace_back(mover);
	character->components.emplace_back(dynamicBoxCollider);

	entities.emplace_back(level);
	entities.emplace_back(character);

	sf::Event event;
	sf::Transform worldTransform;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}

		for (auto& e : entities) {
			e->update();
		}

		window.clear();
		for (auto& e : entities){
			e->draw(window, worldTransform);
		}
		window.display();
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
