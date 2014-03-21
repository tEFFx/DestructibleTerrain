#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Terrain.h"

class Entity
{
public:
	~Entity(void);

	enum EntityType: int{
		PlayerEnt = 0,
		BombEnt,
		WeaponEnt
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
	void toggleGravity(bool on);
	virtual void reset();

	static void updateAll();
	static void drawAll(sf::RenderWindow& window);
	static void resetAll();

protected:
	Entity(void);

	void destroy();

	sf::RectangleShape mHitbox;

	bool mGravityPull;
	float mGravity;
	float mFallVelocity;
	
	EntityType mType;

	sf::Clock mFallTimer;
	sf::Time mFallTime;
	sf::Vector2f mStartPos;

private:
	bool mDestroy;

	static std::vector<Entity*> allEntities;
};

