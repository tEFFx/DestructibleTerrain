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

		Entity* temp = isCollidingWith();

		if(temp != NULL &&
			temp->getType() == EntityType::Player)
		{
			mEntity = isCollidingWith();
		}

		else if(temp != NULL &&
			temp->getType() == EntityType::Weapon)
		{
			mEntity = NULL;
		}
	}

	else{
		mHitbox.setPosition(mEntity->getBox()->getPosition());
		//do stuff
	}
}