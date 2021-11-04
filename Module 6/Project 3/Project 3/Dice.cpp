/*********************************************************************
** Program name: Project3
** Filename: Dice.cpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: This a dice class for use with the Creature class.  
**				It contains a method to return a random number to 
**				represent a die roll.
********************************************************************/

#include "Dice.hpp"

/*Constructors*/

Dice::Dice()
{
	sides = 0;
}

Dice::Dice(int sidesIn, int numIn)
{
	sides = sidesIn;
	numDice = numIn;
}

/*Destructor*/

Dice::~Dice()
{
}

int Dice::getNumDice()
{
	return numDice;
}

/*This function control rolling for the various die types.  A random
  number will be generated based on the sides of the die object.
  The sides of the die determeines the maximum random number. The 
  function will loop through based on the number of dice being used
  summing the results of each roll.  The srand() seed must be in the
  main function.*/

int Dice::roll()
{
	int dieRoll = 0;
	for (int i = 0; i < numDice; i++)
	{
		dieRoll += rand() % sides + 1;
	}
	return dieRoll;
}

/*Method to remove die available for rolling.  Might use 
for the Blue Men mob() function.  Currently not in use.*/

  void Dice::remDie()
  {
	  numDice -= 1;
  }
