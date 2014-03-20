#include "Player.h"


Player::Player(void)
{
	mHitbox.setPosition(500, 200);
	mHitbox.setSize(sf::Vector2f(50, 80));
	mHitbox.setOrigin(25, 40);
	mHitbox.setFillColor(sf::Color::Magenta);

	mSpeed = 2;
	mJump = false;

	mType = EntityType::PlayerEnt;

	mWeapon = NULL;
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

	Entity* temp = isCollidingWith();

	static bool clicked = false;
	if(clicked == false &&
		temp != NULL &&
		temp->getType() == Entity::WeaponEnt &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		if(mWeapon != NULL)
		{
			if(isCollidingExcept(mWeapon) != NULL &&
				isCollidingExcept(mWeapon)->getType() == Entity::WeaponEnt)
			{
				temp = isCollidingExcept(mWeapon);
			}
			mWeapon->toggleGravity(true);
		}
		mWeapon = temp;
		mWeapon->toggleGravity(false);
		clicked = true;
	}

	else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		clicked = false;
	}

	if(mWeapon != NULL)
	{
		mWeapon->getBox()->setPosition(mHitbox.getPosition());
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		mHitbox.move(-mSpeed, 0);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		mHitbox.move(mSpeed, 0);
	}

	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W)) &&
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
		}
	}

	while(checkPixelCollision(Terrain::getInstance().getTerrainImage(), sf::Vector2f(25, 0)) ||
		mHitbox.getPosition().x > 1280)
	{
		mHitbox.move(-mSpeed, 0);
	}

	while(checkPixelCollision(Terrain::getInstance().getTerrainImage(), sf::Vector2f(-25, 0)) ||
		mHitbox.getPosition().x < 0)
	{
		mHitbox.move(mSpeed, 0);
	}

	while(checkPixelCollision(Terrain::getInstance().getTerrainImage(), sf::Vector2f(0, -40)))
	{
		mHitbox.move(0, mFallVelocity);
	}
}