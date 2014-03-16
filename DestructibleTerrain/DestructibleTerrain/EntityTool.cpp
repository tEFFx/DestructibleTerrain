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
		it != mEntites.end();)
	{
		(*it)->update();

		if((*it)->checkDestroy())
		{
			delete (*it);
			it = mEntites.erase(it);
		}

		else{
			it++;
		}
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
