#pragma once
#include "entity.h"
class Player :
	public Entity
{
public:
	~Player(void);

	static Entity* newPlayer();

	virtual void update();

private:
	Player(void);
};

