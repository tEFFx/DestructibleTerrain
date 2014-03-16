#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Terrain.h"

class Entity
{
public:
	virtual void update();
	virtual void draw(sf::RenderWindow& window);
	bool checkPixelCollision(sf::Image* image, sf::Vector2f offset);
	bool checkPixelCollision(sf::Image* image);

protected:
	Entity(void);
	~Entity(void);

	sf::RectangleShape mHitbox;
	float mGravity;
	float mFallVelocity;

private:
	sf::Clock mFallTimer;
	sf::Time mFallTime;
};

