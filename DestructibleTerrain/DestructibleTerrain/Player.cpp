#include "Player.h"


Player::Player(void)
{
	mHitbox.setPosition(200, 200);
	mHitbox.setSize(sf::Vector2f(50, 80));
	mHitbox.setOrigin(25, 40);
	mHitbox.setFillColor(sf::Color::Magenta);

	mSpeed = 2;
	mJump = false;
}


Player::~Player(void)
{
}


Entity* Player::newPlayer()
{
	return new Player();
}

void Player::update()
{
	Entity::update();

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		mHitbox.move(-mSpeed, 0);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		mHitbox.move(mSpeed, 0);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
		checkPixelCollision(Terrain::getInstance().getTerrainImage(), sf::Vector2f(0, 40)))
	{
		mJump = true;
	}

	if(mJump == true)
	{
		float jump = -10+mFallVelocity;
		mHitbox.move(0, jump);

		if(jump >= 0 ||
			checkPixelCollision(Terrain::getInstance().getTerrainImage(), sf::Vector2f(0, 40)))
		{
			mJump = false;
			std::cout << "no more jump" << std::endl;
		}
	}

	while(checkPixelCollision(Terrain::getInstance().getTerrainImage(), sf::Vector2f(25, 0)))
	{
		mHitbox.move(-mSpeed, 0);
	}

	while(checkPixelCollision(Terrain::getInstance().getTerrainImage(), sf::Vector2f(-25, 0)))
	{
		mHitbox.move(mSpeed, 0);
	}

	while(checkPixelCollision(Terrain::getInstance().getTerrainImage(), sf::Vector2f(0, -40)))
	{
		mHitbox.move(0, mFallVelocity);
	}
}