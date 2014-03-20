#include "Bazooka.h"


Bazooka::Bazooka(sf::Vector2f pos)
{
	mHitbox.setPosition(pos);
	mHitbox.setSize(sf::Vector2f(100, 20));
	mHitbox.setOrigin(20, 10);
	mHitbox.setFillColor(sf::Color::Black);

	mFireRate = 1000;
	mRadius = 100;
	mAuto = true;
}


Bazooka::~Bazooka(void)
{
}


Entity* Bazooka::newBazooka(sf::Vector2f pos)
{
	return new Bazooka(pos);
}