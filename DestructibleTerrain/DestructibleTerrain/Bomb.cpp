#include "Bomb.h"


Bomb::Bomb(sf::Vector2f pos, float speed, float dir, float radius)
{
	mHitbox.setSize(sf::Vector2f(30, 10));
	mHitbox.setPosition(pos);
	mHitbox.setOrigin(15, 5);
	mHitbox.setFillColor(sf::Color::Black);
	mHitbox.setRotation(dir);

	mRadius = radius;

	mType = EntityType::Bomb;

	mSpeed.x = speed * cos((dir * 3.14159265359) / 180.f);
	mSpeed.y = speed * sin((dir * 3.14159265359) / 180.f);
	mFallSpeed = mSpeed.y;

	std::cout << dir << std::endl;

	mFallTimer.restart();

	mPos0 = pos;
}


Bomb::~Bomb(void)
{
}

Entity* Bomb::newBomb(sf::Vector2f pos, float speed, float dir, float radius)
{
	return new Bomb(pos, speed, dir, radius);
}

void Bomb::update()
{
	mFallTime = mFallTimer.getElapsedTime();
	mFallVelocity = mGravity * mFallTime.asSeconds();

	if(checkPixelCollision(Terrain::getInstance().getTerrainImage(), sf::Vector2f(0, 0)))
	{
		Terrain::getInstance().createHole(mHitbox.getPosition(), mRadius);
		destroy();
	}

	if(mHitbox.getPosition().y > 720)
	{
		destroy();
	}

	if(mPos0 != mHitbox.getPosition())
	{
		float dir = atan2(mPos0.y - mHitbox.getPosition().y, mPos0.x - mHitbox.getPosition().x) * (180.f / 3.14159265359f);
		mHitbox.setRotation(dir);
	}

	mPos0 = mHitbox.getPosition();

	mSpeed.y = mFallSpeed + mFallVelocity;

	mHitbox.move(mSpeed);
}