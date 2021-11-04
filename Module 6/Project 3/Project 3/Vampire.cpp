/*********************************************************************
** Program name: Project3
** Filename: Vampire.cpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: This the Vampire class derived from the base
**				Creature class.
********************************************************************/

#include "Vampire.hpp"

/*Constructors*/

Vampire::Vampire() : Creature()
{
	atkDice = NULL;
	defDice = NULL;
	name = " ";
}

Vampire::Vampire(const int& strIn, const int& armIn) : Creature(strIn, armIn)
{
	atkDice = new Dice(12, 1);
	defDice = new Dice(6, 1);
	name = "Vampire";
}

/*Destructor*/

Vampire::~Vampire()
{
	delete atkDice;
	atkDice = NULL;

	delete defDice;
	defDice = NULL;
}

/*Function to print the name of the creature.*/

void Vampire::printName()
{
	cout << name;
}

/*Controls the charm power for the Vampire class.  Random value 
generation will result in the attack being nulified half the time.
The rand() function will be seeded in the main function.  True
return means attacker is charmed.*/

bool Vampire::charm()
{
	int charmed = rand() % 2;
	if (charmed)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*Attack function for the Vampire class.  Returns the dice roll of
the Creatures attack.*/

int Vampire::attack()
{
	int atkRolled = atkDice->roll();
	cout << "Attack: " << atkRolled << endl;
	return 	atkRolled;
}

/*Defense function for the Vampire class.  Returns the dice roll of
the result of the Creatures defense subtracted from the attackers
roll.  If the result is negative returns 0.  This function also
displays the results of the defense die roll.  When the Vampire's
charm ability is used the attack is nullified by returning a damage
of 0 and message is displayed stating power was used.*/

int Vampire::defense(int atk)
{
	bool charmDef = charm();
	if (charmDef)
	{
		cout << "Vampire uses charm power!\n";
		return 0;
	}
	else
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
}
