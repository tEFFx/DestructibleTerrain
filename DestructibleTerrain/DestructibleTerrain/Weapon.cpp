#include "Weapon.h"


Weapon::Weapon(void)
{
	mEntity = NULL;

	mType = EntityType::Weapon;

	mFireTime = mFireTimer.getElapsedTime();
	mFire = false;
}


Weapon::~Weapon(void)
{
}


void Weapon::update()
{
	static bool click = false;
	static bool push = false;
	mFireTime = mFireTimer.getElapsedTime();
	Entity* temp = isCollidingWith();

	if(mEntity == NULL)
	{
		Entity::update();

		if(temp != NULL &&
			temp->getType() == EntityType::Player &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::E) &&
			push == false)
		{
			mEntity = temp;
			push = true;
		}
	}
	
	else{
		
		mHitbox.setPosition(mEntity->getBox()->getPosition());

		if(mFire == true &&
			mFireTime.asMilliseconds() > mFireRate)
		{
			mFire = false;
		}

		if(mFire == false &&
			(click == false || mAuto == true) &&
			sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			mFireTime = mFireTimer.getElapsedTime();
			click = true;
			mFire = true;
			mFireTimer.restart();
			
			sf::Vector2f gunpos = mHitbox.getPosition();
			sf::Vector2f barrelpos = sf::Vector2f(cos((mHitbox.getRotation() * 3.14159265359) / 180.f), sin((mHitbox.getRotation() * 3.14159265359) / 180.f));
			sf::Vector2f newpos;
			newpos.x = gunpos.x + mHitbox.getSize().x * barrelpos.x;
			newpos.y = gunpos.y + mHitbox.getSize().x * barrelpos.y;

			Bomb::newBomb(newpos, 10, mHitbox.getRotation(), mRadius);
		}

		else if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && 
			click == true &&
			mAuto == false){
			click = false;
		}

		if(mEntity != NULL &&
			mEntity->isCollidingExcept(this) != NULL &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::E) &&
			push == false)
		{
			mEntity = NULL;
			push = true;
		}
	}

	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		push = false;
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

		mHitbox.setRotation(rot);
	}
}