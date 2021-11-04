/*********************************************************************
** Program name: Project3
** Filename: BlueMen.cpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: This the Vampire class derived from the base
**				Creature class.
********************************************************************/

#include "BlueMen.hpp"

/*Constructors*/

BlueMen::BlueMen() : Creature()
{
	atkDice = NULL;
	defDice = NULL;
	name = " ";
	dmgCheck = 0;
}

BlueMen::BlueMen(const int& strIn, const int& armIn) : Creature(strIn, armIn)
{
	atkDice = new Dice(10, 2);
	defDice = new Dice(6, 3);
	name = "Blue Men";
	dmgCheck = 0;
}

/*Destructor*/

BlueMen::~BlueMen()
{
	delete atkDice;
	atkDice = NULL;

	delete defDice;
	defDice = NULL;
}

/*Function to print the name of the creature.*/

void BlueMen::printName()
{
	cout << name;
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
		defDice = NULL;
		defDice = new Dice(6, 2);
	}
	else if (dmgCheck > 8)
	{
		cout << "Only rolling 1d6 for defense.\n";
		delete defDice;
		defDice = NULL;
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
