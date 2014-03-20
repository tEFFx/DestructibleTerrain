#include "EntityTool.h"

Entity* EntityTool::newPlayer()
{
	return Player::newPlayer();
}

Entity* EntityTool::newBazooka(sf::Vector2f pos)
{
	return Bazooka::newBazooka(pos);
}

Entity* EntityTool::newMachinegun(sf::Vector2f pos)
{
	return Machinegun::newMachinegun(pos);
}

void EntityTool::update()
{
	Entity::updateAll();
}

void EntityTool::draw(sf::RenderWindow& window)
{
	Entity::drawAll(window);
}
