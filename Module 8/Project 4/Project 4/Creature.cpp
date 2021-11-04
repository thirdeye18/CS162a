/*********************************************************************
** Program name: Project 4
** Filename: Creature.cpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: This is the abstract Creature class. It contains 
**				constructors and a method for tracking the current
**				strength of the creature during combat.
********************************************************************/

#include "Creature.hpp"

/*Constructors*/

Creature::Creature()
{
	strength = 0;
	armour = 0;
}

Creature::Creature(const int& str, const int& arm)
{
	strength = str;
	armour = arm;
}

/*Destructor*/

Creature::~Creature()
{
}

/*Getters for Creature attributes*/

int Creature::getStr()
{
	return strength;
}

int Creature::getArm()
{
	return armour;
}

/*Adjusts the strength for the creatures when damage is dealt.
  Damage is calculated by subtracting the armour value from the 
  damages dealt.*/

void Creature::damage(int dmg)
{
	if ((dmg - armour) >= 0)
	{
		cout << "Damage: " << (dmg - armour) << endl;
		strength -= (dmg - armour);
	}
	else
	{
		cout << "Damage: 0" << endl;
	}
}

/*Assigns string input from the user as the name of the creature.
Input validation method for strings used to verify that a blank 
string is not applied to the user name.*/

void Creature::assignName()
{
	cout << "Please enter a name for the creature. ";
	cout << "The name cannot be blank.\n";

	string nameChoice = "";
	while (!stringValidation(nameChoice))
	{
		getline(cin, nameChoice);
		if (!stringValidation(nameChoice))
		{
			cout << "The name cannot be blank\n";
			string nameChoice = "";
		}
	}
	name = nameChoice;
}
