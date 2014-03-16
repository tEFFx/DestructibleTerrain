#include "Bomb.h"


Bomb::Bomb(sf::Vector2f pos)
{
	mHitbox.setSize(sf::Vector2f(50, 50));
	mHitbox.setPosition(pos);
	mHitbox.setOrigin(25, 25);
	mHitbox.setFillColor(sf::Color::Black);
}


Bomb::~Bomb(void)
{
}

Entity* Bomb::newBomb(sf::Vector2f pos)
{
	return new Bomb(pos);
}

void Bomb::update()
{
	Entity::update();
}