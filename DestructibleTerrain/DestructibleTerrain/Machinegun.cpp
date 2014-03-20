#include "Machinegun.h"


Machinegun::Machinegun(sf::Vector2f pos)
{
	mHitbox.setPosition(pos);
	mHitbox.setSize(sf::Vector2f(75, 15));
	mHitbox.setOrigin(32, 7);
	mHitbox.setFillColor(sf::Color::Blue);

	mFireRate = 100;
	mRadius = 20;
	mAuto = true;
}


Machinegun::~Machinegun(void)
{
}


Entity* Machinegun::newMachinegun(sf::Vector2f pos)
{
	return new Machinegun(pos);
}