#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Entity.h"
#include "Bomb.h"
#include "Player.h"

typedef std::vector<Entity*> Entities;

class EntityTool
{
public:
	static Entity* newBomb(sf::Vector2f pos);
	static Entity* newPlayer();

	static void update();
	static void draw(sf::RenderWindow& window);

private:
	EntityTool(void);
	~EntityTool(void);
	static Entities mEntites;
};

