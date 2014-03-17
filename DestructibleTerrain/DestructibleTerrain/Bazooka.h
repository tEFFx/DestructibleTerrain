#pragma once
#include "weapon.h"
class Bazooka :
	public Weapon
{
public:
	static Entity* newBazooka(sf::Vector2f pos);


private:
	Bazooka(sf::Vector2f pos);
	~Bazooka(void);
};

