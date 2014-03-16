#include "Entity.h"


Entity::Entity(void)
{
	mGravity = 9.82f;
	mFallVelocity = 0;
}


Entity::~Entity(void)
{
}


void Entity::update()
{
	sf::Image terrain = Terrain::getInstance().getTerrainImage();
	if(!checkPixelCollision(&terrain))
	{
		mFallTime = mFallTimer.getElapsedTime();
		mFallVelocity = mGravity * mFallTime.asSeconds();
		mHitbox.move(0, mFallVelocity);
	}

	else{
		mFallTimer.restart();
	}
}

void Entity::draw(sf::RenderWindow& window)
{
	window.draw(mHitbox);
}

bool Entity::checkPixelCollision(sf::Image* image, sf::Vector2f offset)
{
	if(image->getPixel(mHitbox.getPosition().x + offset.x, mHitbox.getPosition().y + offset.y).a != 0)
	{
		return true;
	}

	else{
		return false;
	}
}

bool Entity::checkPixelCollision(sf::Image* image)
{
	if(image->getPixel(mHitbox.getPosition().x, mHitbox.getPosition().y).a != 0)
	{
		return true;
	}

	else{
		return false;
	}
}