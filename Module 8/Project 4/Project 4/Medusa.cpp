/*********************************************************************
** Program name: Project 4
** Filename: Medusa.cpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: This the Medusa class derived from the base
**				Creature class.
********************************************************************/

#include "Medusa.hpp"

/*Constructors*/

Medusa::Medusa() : Creature(MED_STR, MED_ARM)
{
	atkDice = new Dice(6, 2);
	defDice = new Dice(6, 1);
	type = "Medusa";
	assignName();
}

/*Destructor*/

Medusa::~Medusa()
{
	delete atkDice;
	atkDice = nullptr;

	delete defDice;
	defDice = nullptr;
}

/*Function to print the name of the creature.*/

void Medusa::printName()
{
	cout << name;
}

/*Function to print the type of the creature.*/

void Medusa::printType()
{
	cout << type;
}

/*Attack function for the Medusa class.  Returns the dice roll of
the Creatures attack.  If the roll is a 12 will return an attack 
value of 50 and a message displaying that gaze power was used.*/

int Medusa::attack()
{
	int atkRoll = atkDice->roll();
	if (atkRoll == 12)
	{
		cout << "Medusa uses gaze attack!\n";
		return 50;
	}
	else
	{
		cout << "Attack: " << atkRoll << endl;
		return atkRoll;
	}
}

/*Defense function for the Medusa class.  Returns the dice roll of
the result of the Creatures defense subtracted from the attackers
roll.  If the result is negative returns 0.  This function also
displays the results of the defense die roll. */

int Medusa::defense(int atk)
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

void Medusa::heal()
{
	int totalDamage = 0;
	totalDamage = MED_STR - strength;
	strength += 0.7 * totalDamage;
}
