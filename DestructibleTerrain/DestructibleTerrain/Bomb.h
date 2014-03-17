#pragma once
#include "entity.h"
class Bomb :
	public Entity
{
public:
	static Entity* newBomb(sf::Vector2f pos, float speed, float dir);
	virtual void update();

private:
	Bomb(sf::Vector2f pos, float speed, float dir);
	~Bomb(void);

	sf::Vector2f mSpeed;
	float mFallSpeed;
};

