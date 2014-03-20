#pragma once
#include "Weapon.h"
class Machinegun :
	public Weapon
{
public:
	static Entity* newMachinegun(sf::Vector2f pos);

private:
	Machinegun(sf::Vector2f pos);
	~Machinegun(void);
};

