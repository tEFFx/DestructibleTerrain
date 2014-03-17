#pragma once
#include <SFML\Graphics.hpp>
#include "Entity.h"

class Weapon:
	public Entity
{
public:
	virtual void update();
	virtual void draw(sf::RenderWindow& window);

protected:
	Weapon(void);
	~Weapon(void);

	sf::RectangleShape mHitbox;
	sf::Clock mFireTimer;
	sf::Time mFireTime;
	Entity* mEntity;
	float mRadius, mFireRate;
	bool mAuto;
};

