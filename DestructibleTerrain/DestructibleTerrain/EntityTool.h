#pragma once
#include <SFML\Graphics.hpp>
#include "Entity.h"
#include "Bomb.h"
#include "Player.h"


struct EntityTool
{
	static Entity* newBomb(sf::Vector2f pos);
	static Entity* newPlayer();

	static void update();
	static void draw(sf::RenderWindow& window);
};

