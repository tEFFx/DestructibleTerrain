#pragma once
#include "entity.h"
class Bomb :
	public Entity
{
public:
	static Entity* newBomb(sf::Vector2f pos);
	virtual void update();

private:
	Bomb(sf::Vector2f pos);
	~Bomb(void);
};

