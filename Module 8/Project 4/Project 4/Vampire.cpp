/*********************************************************************
** Program name: Project 4
** Filename: Vampire.cpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: This the Vampire class derived from the base
**				Creature class.
********************************************************************/

#include "Vampire.hpp"

/*Constructors*/

Vampire::Vampire() : Creature(VAMP_STR, VAMP_ARM)
{
	atkDice = new Dice(12, 1);
	defDice = new Dice(6, 1);
	type = "Vampire";
	assignName();
}

/*Destructor*/

Vampire::~Vampire()
{
	delete atkDice;
	atkDice = nullptr;

	delete defDice;
	defDice = nullptr;
}

/*Function to print the name of the creature.*/

void Vampire::printName()
{
	cout << name;
}

/*Function to print the type of the creature.*/

void Vampire::printType()
{
	cout << type;
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
charm ability is used the attack is nullptrified by returning a damage
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

/*Method to heal 70% creature health lost after winning combat and 
going back to the queue.  70% of the damage received will be added
back to the creatures strength, not to exceed the max strength. Uses
the constant creature stat values in creature.hpp to determine damage
taken and what the max strength is.*/

void Vampire::heal()
{
	int totalDamage = 0;
	totalDamage = VAMP_STR - strength;
	strength += 0.7 * totalDamage;
}
