/*********************************************************************
** Program name: Final Project
** Filename: Dice.cpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This a dice class for use with the Escape the Temple
**				Final Project. It contains a method to return a  
**				random number to represent a die roll. The die rolls 
**				will be converted to a char and stored in a vector.
********************************************************************/

#include "Dice.hpp"

/*Constructors*/

Dice::Dice()
{
	sides = 0;
	numDice = 0;
}

Dice::Dice(const int &sidesIn, const int &numIn)
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

/*This function control rolling for the dice.  A random
  number will be generated based on the sides of the die object.
  The sides of the die determeines the maximum random number. The 
  function will loop through based on the number of dice being used.
  Results of the roll are converted to a char and then stored in the 
  results vector.  The srand() seed must be in the main function.*/

void Dice::roll()
{
	char rollChar = ' ';
	for (int i = 0; i < numDice; i++)
	{
		rollChar = convertRoll(rand() % sides + 1);
		diceResults.push_back(rollChar);
	}
}

/*Method to remove die available for rolling.  Useable when black 
skull rolled in the escape the temple game.*/

  void Dice::remDie()
  {
	  numDice -= 1;
  }

  /*Converts "rolled" numbers to a die character for the escape
  the temple game. Roll of 1 becomes k (key), 2/3 becomes 
  a (dventurer), 4 becomes t (torch), 5 becomes b (black skull),
  and 6 becomes g (gold skull).*/

char Dice::convertRoll(int rolledNum)
{
	if (rolledNum == 1)
	{
		return 'k';
	}
	if (rolledNum == 2 || rolledNum == 3)
	{
		return 'a';
	}
	if (rolledNum == 4)
	{
		return 't';
	}
	if (rolledNum == 5)
	{
		return 'b';
	}
	if (rolledNum == 1)
	{
		return 'k';
	}
}
