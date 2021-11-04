/*********************************************************************
** Program name: Project3
** Filename: HarryPotter.cpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: This the HarryPotter class derived from the base
**				Creature class.
********************************************************************/

#include "HarryPotter.hpp"

/*Constructors*/

HarryPotter::HarryPotter() : Creature()
{
	atkDice = NULL;
	defDice = NULL;
	name = " ";
	lifeCounter = 0;
}

HarryPotter::HarryPotter(const int& strIn, const int& armIn) : Creature(strIn, armIn)
{
	atkDice = new Dice(6, 2);
	defDice = new Dice(6, 2);
	name = "Harry Potter";
	lifeCounter = 0;
}

/*Destructor*/

HarryPotter::~HarryPotter()
{
	delete atkDice;
	atkDice = NULL;

	delete defDice;
	defDice = NULL;
}

/*Function to print the name of the creature.*/

void HarryPotter::printName()
{
	cout << name;
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
