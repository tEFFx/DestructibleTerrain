#include "EntityTool.h"

Entity* EntityTool::newBomb(sf::Vector2f pos)
{
	return Bomb::newBomb(pos);
}

Entity* EntityTool::newPlayer()
{
	return Player::newPlayer();
}

Entity* EntityTool::newBazooka(sf::Vector2f pos)
{
	return Bazooka::newBazooka(pos);
}

void EntityTool::update()
{
	Entity::updateAll();
}

void EntityTool::draw(sf::RenderWindow& window)
{
	Entity::drawAll(window);
}
