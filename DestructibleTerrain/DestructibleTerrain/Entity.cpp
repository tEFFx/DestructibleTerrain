#include "Entity.h"

std::vector<Entity*> Entity::allEntities;

Entity::Entity(void)
{
	mGravity = 9.82f;
	mFallVelocity = 1;
	mDestroy = false;

	allEntities.push_back(this);
}


Entity::~Entity(void)
{
}


void Entity::update()
{
	if(!checkPixelCollision(Terrain::getInstance().getTerrainImage(), sf::Vector2f(0, mHitbox.getSize().y/2)))
	{
		mFallTime = mFallTimer.getElapsedTime();
		mFallVelocity = mGravity * mFallTime.asSeconds();
		mHitbox.move(0, mFallVelocity);
	}

	else{
		mFallTimer.restart();

		while(checkPixelCollision(Terrain::getInstance().getTerrainImage(), sf::Vector2f(0, mHitbox.getSize().y/2)))
		{
			mHitbox.move(0, -mFallVelocity);
		}

		mFallVelocity = 1;
	}
}

void Entity::draw(sf::RenderWindow& window)
{
	window.draw(mHitbox);
}

bool Entity::checkPixelCollision(sf::Image& image, sf::Vector2f offset)
{
	if(mHitbox.getPosition().x + offset.x >= 0 &&
		mHitbox.getPosition().y + offset.y >= 0 &&
		mHitbox.getPosition().x + offset.x <= image.getSize().x &&
		mHitbox.getPosition().y + offset.y <= image.getSize().y &&
		image.getPixel(mHitbox.getPosition().x + offset.x, mHitbox.getPosition().y + offset.y).a != 0)
	{
		return true;
	}

	else{
		return false;
	}
}

bool Entity::checkPixelCollision(sf::Image& image)
{
	if(mHitbox.getPosition().x >= 0 &&
		mHitbox.getPosition().y >= 0 &&
		mHitbox.getPosition().x <= image.getSize().x &&
		mHitbox.getPosition().y <= image.getSize().y &&
		image.getPixel(mHitbox.getPosition().x, mHitbox.getPosition().y).a != 0)
	{
		return true;
	}

	else{
		return false;
	}
}

void Entity::destroy()
{
	mDestroy = true;
}

bool Entity::checkDestroy()
{
	return mDestroy;
}

sf::RectangleShape* Entity::getBox()
{
	return &mHitbox;
}

Entity::EntityType Entity::getType()
{
	return mType;
}

Entity* Entity::isCollidingWith()
{
	auto temp = allEntities;
	for(auto it = temp.begin();
		it != temp.end();
		it++)
	{
		if(this != (*it) &&
			mHitbox.getGlobalBounds().intersects((*it)->mHitbox.getGlobalBounds()))
		{
			return (*it);
		}
	}

	return NULL;
}


void Entity::updateAll()
{
	auto temp = allEntities;
	for(auto it = temp.begin();
		it != temp.end();
		it++)
	{
		(*it)->update();
	}

	for(auto it = allEntities.begin();
		it != allEntities.end();)
	{
		if((*it)->checkDestroy())
		{
			delete (*it);
			it = allEntities.erase(it);
		}

		else{
			it++;
		}
	}
}

void Entity::drawAll(sf::RenderWindow& window)
{
	auto temp = allEntities;
	for(auto it = temp.begin();
		it != temp.end();
		it++)
	{
		(*it)->draw(window);
	}
}