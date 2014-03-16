#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Terrain.h"

class Entity
{
public:
	~Entity(void);

	virtual void update();
	virtual void draw(sf::RenderWindow& window);
	bool checkPixelCollision(sf::Image* image, sf::Vector2f offset);
	bool checkPixelCollision(sf::Image* image);
	bool checkDestroy();

protected:
	Entity(void);

	void destroy();

	sf::RectangleShape mHitbox;
	float mGravity;
	float mFallVelocity;

private:
	sf::Clock mFallTimer;
	sf::Time mFallTime;
	bool mDestroy;
};

