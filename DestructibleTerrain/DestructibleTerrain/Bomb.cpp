#include "Bomb.h"


Bomb::Bomb(sf::Vector2f pos, float speed, float dir)
{
	mHitbox.setSize(sf::Vector2f(30, 30));
	mHitbox.setPosition(pos);
	mHitbox.setOrigin(15, 15);
	mHitbox.setFillColor(sf::Color::Black);

	mType = EntityType::Bomb;

	mSpeed.x = speed * cos((dir * 3.14159265359) / 180.f);
	mSpeed.y = speed * sin((dir * 3.14159265359) / 180.f);
	mFallSpeed = mSpeed.y;

	std::cout << dir << std::endl;

	mFallTimer.restart();
}


Bomb::~Bomb(void)
{
}

Entity* Bomb::newBomb(sf::Vector2f pos, float speed, float dir)
{
	return new Bomb(pos, speed, dir);
}

void Bomb::update()
{
	mFallTime = mFallTimer.getElapsedTime();
	mFallVelocity = mGravity * mFallTime.asSeconds();

	if(checkPixelCollision(Terrain::getInstance().getTerrainImage(), sf::Vector2f(0, 0)))
	{
		Terrain::getInstance().createHole(mHitbox.getPosition(), 100);
		destroy();
	}

	if(mHitbox.getPosition().y > 720)
	{
		destroy();
	}

	mSpeed.y = mFallSpeed + mFallVelocity;

	mHitbox.move(mSpeed);
}