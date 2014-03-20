#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Terrain.h"

class Entity
{
public:
	~Entity(void);

	enum EntityType: int{
		Player = 0,
		Bomb,
		Weapon
	};

	virtual void update();
	virtual void draw(sf::RenderWindow& window);
	bool checkPixelCollision(sf::Image& image, sf::Vector2f offset);
	bool checkPixelCollision(sf::Image& image);
	bool checkDestroy();
	sf::RectangleShape* getBox();
	EntityType getType();
	Entity* isCollidingWith();
	Entity* isCollidingExcept(Entity* except);

	static void updateAll();
	static void drawAll(sf::RenderWindow& window);

protected:
	Entity(void);

	void destroy();

	sf::RectangleShape mHitbox;

	float mGravity;
	float mFallVelocity;
	
	EntityType mType;

	sf::Clock mFallTimer;
	sf::Time mFallTime;

private:
	bool mDestroy;

	static std::vector<Entity*> allEntities;
};

