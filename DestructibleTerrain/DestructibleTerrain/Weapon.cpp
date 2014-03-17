#include "Weapon.h"


Weapon::Weapon(void)
{
	mEntity = NULL;

	mType = EntityType::Weapon;
}


Weapon::~Weapon(void)
{
}


void Weapon::update()
{
	if(mEntity == NULL)
	{
		Entity::update();

		if(isCollidingWith()->getType() == EntityType::Player)
		{
			mEntity = isCollidingWith();
		}

		else if(isCollidingWith()->getType() == EntityType::Weapon)
		{
			mEntity = NULL;
		}
	}

	else{
		//do stuff
	}
}