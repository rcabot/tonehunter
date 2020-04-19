#include <iostream>
#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"
#include "TileMap.h"
#include "Character.h"
#include "tonehunter.h"
#include "Entity.h"

int main()
{
	const float FPS = 60.0f; //The desired FPS. (The number of updates each second).
	//PlatformHelper platform;
	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	//float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	float screenScalingFactor = 1.0f;
	window.create(sf::VideoMode(400.0f * screenScalingFactor, 400.0f * screenScalingFactor),
		"Rachel's very special game!");
	window.setFramerateLimit(FPS);
	std::vector<std::unique_ptr<Entity>> entities;


	b2Vec2 gravity(0.0f, 0.0f);
	b2World world(gravity);

	//platform.setIcon(window.getSystemHandle());

	// define the level with an array of tile indices
	const int level[] =
	{
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
	};

	// create the tilemap from the level definition
	auto map = new TileMap;
	if (!map->load(
		"content/colored_tilemap_packed.png", 
		sf::Vector2u(8, 8),
		sf::Vector2u(4, 4), 
		level, 16, 8)) {
		return -1;
	}

	auto characterSpriteRenderer = new SpriteSheetSpriteRenderer;
	if (!characterSpriteRenderer->load(
		"content/colored_tilemap_packed.png", 
		sf::Vector2u(8, 8), 
		sf::Vector2u(4, 4), 7)) {
		return -1;
	}
	auto character = new Character;
	character->drawables.emplace_back(characterSpriteRenderer);
	//character.setOrigin(10.0f, 10.0f);
	//character.setPosition(0, 150.0f);

	entities.emplace_back(map);
	entities.emplace_back(character);

	sf::Event event;
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
			auto d = e.get();
			window.draw(*d);
		}
		window.display();
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
