#include "Machinegun.h"


Machinegun::Machinegun(sf::Vector2f pos)
{
	mHitbox.setPosition(pos);
	mHitbox.setSize(sf::Vector2f(50, 10));
	mHitbox.setOrigin(10, 5);
	mHitbox.setFillColor(sf::Color::Blue);

	mFireRate = 100;
	mRadius = 25;
	mAuto = true;
}


Machinegun::~Machinegun(void)
{
}


Entity* Machinegun::newMachinegun(sf::Vector2f pos)
{
	return new Machinegun(pos);
}