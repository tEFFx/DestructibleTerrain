#pragma once
#include <SFML\Graphics.hpp>
#include "Entity.h"
#include "Bomb.h"

class Weapon:
	public Entity
{
public:
	virtual void update();
	virtual void draw(sf::RenderWindow& window);

	~Weapon(void);

protected:
	Weapon(void);

	sf::Clock mFireTimer;
	sf::Time mFireTime;
	Entity* mEntity;
	float mRadius, mFireRate;
	bool mAuto;
};

