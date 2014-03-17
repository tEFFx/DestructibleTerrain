#pragma once
#include <SFML\Graphics.hpp>
#include "Entity.h"

class Weapon:
	public Entity
{
public:
	virtual void update();

	~Weapon(void);

protected:
	Weapon(void);

	sf::Clock mFireTimer;
	sf::Time mFireTime;
	Entity* mEntity;
	float mRadius, mFireRate;
	bool mAuto;
};

