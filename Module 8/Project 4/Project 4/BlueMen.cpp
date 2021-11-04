/*********************************************************************
** Program name: Project 4
** Filename: BlueMen.cpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: This the Vampire class derived from the base
**				Creature class.
********************************************************************/

#include "BlueMen.hpp"

/*Constructors*/

BlueMen::BlueMen() : Creature(BLUE_STR, BLUE_ARM)
{
	atkDice = new Dice(10, 2);
	defDice = new Dice(6, 3);
	type = "Blue Men";
	dmgCheck = 0;
	assignName();
}

/*Destructor*/

BlueMen::~BlueMen()
{
	delete atkDice;
	atkDice = nullptr;

	delete defDice;
	defDice = nullptr;
}

/*Function to print the name of the creature.*/

void BlueMen::printName()
{
	cout << name;
}

/*Function to print the type of the creature.*/

void BlueMen::printType()
{
	cout << type;
}

/*Controls the mob ability for the Blue Men class.  As the Blue Men
strength decreases their defense dice are deleted and re-allocated
to reflect the new defense stats.  At 8 they have 2d6 defense and at
4 only 1d6.*/

void BlueMen::mob()
{
	if (dmgCheck > 3 && dmgCheck < 8)
	{
		cout << "Only rolling 2d6 for defense.\n";
		delete defDice;
		defDice = nullptr;
		defDice = new Dice(6, 2);
	}
	else if (dmgCheck > 8)
	{
		cout << "Only rolling 1d6 for defense.\n";
		delete defDice;
		defDice = nullptr;
		defDice = new Dice(6, 1);
	}
}

/*Attack function for the Blue Men class.  Returns the dice roll of
the Creatures attack.*/

int BlueMen::attack()
{
	int atkRolled = atkDice->roll();
	cout << "Attack: " << atkRolled << endl;
	return 	atkRolled;
}

/*Defense function for the Blue Men class.  Returns the dice roll of
the result of the Creatures defense subtracted from the attackers
roll.  If the result is negative returns 0.  This function also
displays the results of the defense die roll. Blue Men mob() method
called each time defense is used to determine the number of defense
dice for the Blue Men to have.  Message will be displayed if the 
defense dice are re-allocated.*/

int BlueMen::defense(int atk)
{
	int def = defDice->roll();
	cout << "Defense: " << def << endl;
	cout << "Rolling " << defDice->getNumDice() << endl;

	//no damage situation
	if ((atk - (def + armour)) < 0)
	{
		return 0;
	}

	//damage will be dealt
	else
	{
		dmgCheck += atk - (def + armour);
		mob();
		return atk - def;
	}
}

/*Method to heal 70% creature health lost after winning combat and
going back to the queue.  70% of the damage received will be added
back to the creatures strength, not to exceed the max strength. Uses
the constant creature stat values in creature.hpp to determine damage
taken and what the max strength is.*/

void BlueMen::heal()
{
	int totalDamage = 0;
	totalDamage = BLUE_STR - strength;
	strength += 0.7 * totalDamage;
}
