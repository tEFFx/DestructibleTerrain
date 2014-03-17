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

void Weapon::draw(sf::RenderWindow& window)
{
	Entity::draw(window);

	if(mEntity != NULL)
	{
		sf::Vector2f entPos = mEntity->getBox()->getPosition();
		sf::Vector2f mouPos = sf::Vector2f(sf::Mouse::getPosition(window));
		float rot = atan2(mouPos.y - entPos.y, mouPos.x - entPos.x) * (180.f / 3.14159265359f);

		std::cout << rot << std::endl;

		mHitbox.setRotation(rot);
	}
}