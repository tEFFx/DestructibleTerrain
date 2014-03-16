#include "Player.h"


Player::Player(void)
{
	mHitbox.setPosition(200, 200);
	mHitbox.setSize(sf::Vector2f(50, 80));
	mHitbox.setOrigin(25, 40);
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
		mHitbox.move(-1, 0);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		mHitbox.move(1, 0);
	}
}