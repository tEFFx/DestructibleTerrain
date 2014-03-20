#pragma once
#include "entity.h"
class Bomb :
	public Entity
{
public:
	static Entity* newBomb(sf::Vector2f pos, float speed, float dir, float radius);
	virtual void update();

private:
	Bomb(sf::Vector2f pos, float speed, float dir, float radius);
	~Bomb(void);

	sf::Vector2f mSpeed;
	sf::Vector2f mPos0;
	float mRadius;
	float mFallSpeed;
};

