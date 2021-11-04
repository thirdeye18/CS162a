/*********************************************************************
** Program name: Project 4
** Filename: HarryPotter.cpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: This the HarryPotter class derived from the base
**				Creature class.
********************************************************************/

#include "HarryPotter.hpp"

/*Constructors*/

HarryPotter::HarryPotter() : Creature(HP_STR, HP_ARM)
{
	atkDice = new Dice(6, 2);
	defDice = new Dice(6, 2);
	type = "Harry Potter";
	lifeCounter = 0;
	assignName();
}

/*Destructor*/

HarryPotter::~HarryPotter()
{
	delete atkDice;
	atkDice = nullptr;

	delete defDice;
	defDice = nullptr;
}

/*Function to print the name of the creature.*/

void HarryPotter::printName()
{
	cout << name;
}

/*Function to print the type of the creature.*/

void HarryPotter::printType()
{
	cout << type;
}

/*Harry Potter returns to Hogwarts.  Harry Potter strength is boosted
to 20 and lifeCounter is set to 1. */

void HarryPotter::hogwarts()
{
	strength = 20;
	lifeCounter = 1;
	cout << "Harry Potter Died!\n";
	cout << "Harry Potter uses Hogwart's power to ressurrect!\n";
}

/*Attack function for the Harry Potter class.  Returns the dice 
roll of the Creatures attack. */

int HarryPotter::attack()
{
	int atkRolled = atkDice->roll();
	cout << "Attack: " << atkRolled << endl;
	return atkRolled;
}

/*Defense function for the Harry Potter class.  Returns the dice roll
of the result of the Creatures defense subtracted from the attackers
roll.  If the result is negative returns 0.  This function also
displays the results of the defense die roll. */

int HarryPotter::defense(int atk)
{
	int def = defDice->roll();
	cout << "Defense: " << def << endl;
	if ((atk - def) < 0)
	{
		return 0;
	}
	else
	{
		int damage = atk - (def + armour);
		if ((strength - damage) < 1 && lifeCounter == 0)
		{
			hogwarts();
			return 0;
		}
		return damage;
	}
}

/*Method to heal 70% creature health lost after winning combat and
going back to the queue.  70% of the damage received will be added
back to the creatures strength, not to exceed the max strength. Uses
the constant creature stat values in creature.hpp to determine damage
taken and what the max strength is.*/

void HarryPotter::heal()
{
	int totalDamage = 0;
	totalDamage = HP_STR - strength;
	strength += 0.7 * totalDamage;
}
