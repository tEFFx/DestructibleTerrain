#include "Bomb.h"


Bomb::Bomb(sf::Vector2f pos)
{
	mHitbox.setSize(sf::Vector2f(50, 50));
	mHitbox.setPosition(pos);
	mHitbox.setOrigin(25, 25);
	mHitbox.setFillColor(sf::Color::Black);

	mType = EntityType::Bomb;
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

	if(checkPixelCollision(Terrain::getInstance().getTerrainImage(), sf::Vector2f(0, mHitbox.getSize().y/2)))
	{
		Terrain::getInstance().createHole(mHitbox.getPosition(), 100);
		destroy();
	}

	if(mHitbox.getPosition().y > 720)
	{
		destroy();
	}
}