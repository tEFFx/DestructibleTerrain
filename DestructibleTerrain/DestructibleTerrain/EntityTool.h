#pragma once
#include <SFML\Graphics.hpp>
#include "Entity.h"
#include "Bomb.h"
#include "Player.h"
#include "Bazooka.h"


struct EntityTool
{
	static Entity* newPlayer();
	static Entity* newBazooka(sf::Vector2f pos);

	static void update();
	static void draw(sf::RenderWindow& window);
};

