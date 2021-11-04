/*********************************************************************
** Program name: Project3
** Filename: Creature.cpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: This is the abstract Creature class. It contains 
**				constructors and a method for tracking the current
**				strength of the creature during combat.
********************************************************************/

#include "Creature.hpp"

/*Constructors*/

Creature::Creature()
{
	strength = 0;
	armour = 0;
}

Creature::Creature(const int& str, const int& arm)
{
	strength = str;
	armour = arm;
}

/*Destructor*/

Creature::~Creature()
{
}

/*Getters for Creature attributes*/

int Creature::getStr()
{
	return strength;
}

int Creature::getArm()
{
	return armour;
}

/*Adjusts the strength for the creatures when damage is dealt.
  Damage is calculated by subtracting the armour value from the 
  damages dealt.*/

void Creature::damage(int dmg)
{
	if ((dmg - armour) >= 0)
	{
		cout << "Damage: " << (dmg - armour) << endl;
		strength -= (dmg - armour);
	}
	else
	{
		cout << "Damage: 0" << endl;
	}
}
