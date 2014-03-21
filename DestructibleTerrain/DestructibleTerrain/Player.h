#pragma once
#include "Entity.h"
#include "Weapon.h"
class Player :
	public Entity
{
public:
	~Player(void);

	static Entity* newPlayer();

	virtual void update();
	virtual void reset();

private:
	Player(void);
	bool mJump;
	float mSpeed;
	Entity* mWeapon;
};

