/*********************************************************************
** Program name: Project3
** Filename: Barbarian.cpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: This the Barbarian class derived from the base 
**				Creature class.
********************************************************************/

#include "Barbarian.hpp"

/*Constructors*/

Barbarian::Barbarian() : Creature()
{
	atkDice = NULL;
	defDice = NULL;
	name = " ";
}

Barbarian::Barbarian(const int& strIn, const int& armIn) : Creature(strIn, armIn)
{
	atkDice = new Dice(6, 2);
	defDice = new Dice(6, 2);
	name = "Barbarian";
}

/*Destructor*/

Barbarian::~Barbarian()
{
	delete atkDice;
	atkDice = NULL;

	delete defDice;
	defDice = NULL;
}

/*Function to print the name of the creature.*/

void Barbarian::printName()
{
	cout << name;
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
