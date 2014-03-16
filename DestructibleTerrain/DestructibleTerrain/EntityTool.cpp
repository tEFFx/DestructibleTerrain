#include "EntityTool.h"

Entities EntityTool::mEntites;

Entity* EntityTool::newBomb(sf::Vector2f pos)
{
	Entity* temp = Bomb::newBomb(pos);
	mEntites.push_back(temp);
	return temp;
}

void EntityTool::update()
{
	for(auto it = mEntites.begin();
		it != mEntites.end();
		it++)
	{
		(*it)->update();
	}
}

void EntityTool::draw(sf::RenderWindow& window)
{
	for(auto it = mEntites.begin();
		it != mEntites.end();
		it++)
	{
		(*it)->draw(window);
	}
}
