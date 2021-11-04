/*********************************************************************
** Program name: Project3
** Filename: Medusa.cpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: This the Medusa class derived from the base
**				Creature class.
********************************************************************/

#include "Medusa.hpp"

/*Constructors*/

Medusa::Medusa() : Creature()
{
	atkDice = NULL;
	defDice = NULL;
	name = " ";
}

Medusa::Medusa(const int& strIn, const int& armIn) : Creature(strIn, armIn)
{
	atkDice = new Dice(6, 2);
	defDice = new Dice(6, 1);
	name = "Medusa";
}

/*Destructor*/

Medusa::~Medusa()
{
	delete atkDice;
	atkDice = NULL;

	delete defDice;
	defDice = NULL;
}

/*Function to print the name of the creature.*/

void Medusa::printName()
{
	cout << name;
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
