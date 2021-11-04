/*********************************************************************
** Program name: Project 4
** Filename: Barbarian.cpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: This the Barbarian class derived from the base 
**				Creature class.
********************************************************************/

#include "Barbarian.hpp"

/*Constructors*/

Barbarian::Barbarian() : Creature(BARB_STR, BARB_ARM)
{
	atkDice = new Dice(6, 2);
	defDice = new Dice(6, 2);
	type = "Barbarian";
	assignName();
}

/*Destructor*/

Barbarian::~Barbarian()
{
	delete atkDice;
	atkDice = nullptr;

	delete defDice;
	defDice = nullptr;
}

/*Function to print the name of the creature.*/

void Barbarian::printName()
{
	cout << name;
}

/*Function to print the type of the creature.*/

void Barbarian::printType()
{
	cout << type;
}

/*Attack function for the Barbarian class.  Returns the dice roll of
the Creatures attack.*/

int Barbarian::attack()
{
	int atkRolled = atkDice->roll();
	cout << "Attack: " << atkRolled << endl;
	return 	atkRolled;
}

/*Defense function for the Barbarian class.  Returns the dice roll of
the result of the Creatures defense subtracted from the attackers 
roll.  If the result is negative returns 0.  This function also 
displays the results of the defense die roll.*/

int Barbarian::defense(int atk)
{
	int def = defDice->roll();
	cout << "Defense: " << def << endl;
	if ((atk - def) < 0)
	{
		return 0;
	}
	else
	{
		return atk - def;
	}
}

/*Method to heal 70% creature health lost after winning combat and
going back to the queue.  70% of the damage received will be added
back to the creatures strength, not to exceed the max strength. Uses
the constant creature stat values in creature.hpp to determine damage
taken and what the max strength is.*/

void Barbarian::heal()
{
	int totalDamage = 0;
	totalDamage = BARB_STR - strength;
	strength += 0.7 * totalDamage;
}
