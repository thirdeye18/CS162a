/*********************************************************************
** Program name: Lab3
** Filename: Die.cpp
** Author: Justin Hammel
** Date: 4/24/2017
** Description: This is the Die class file which is the parent file for
**				the LoadedDie class.
*********************************************************************/

#include "Die.hpp"

/*Default die constructor, sets sides to 0*/

Die::Die()
{
	setSides(0);
}

/*Die constructor with parameters, sets sides to value of passed 
  int*/

Die::Die(int sidesIn)
{
	setSides(sidesIn);
}

Die::~Die()
{
}

/*Setters and getters for protected values*/

void Die::setSides(const int& N)
{
	this->N = N;
}

void Die::setLoaded(const bool& loaded)
{
	this->loaded = loaded;
}

int Die::getSides() const
{
	return N;
}

bool Die::getLoaded() const
{
	return loaded;
}

/*This function allows the user to input the number of sides they 
  would like the die to be.  Input validation will verify that the
  value is an even integer >= 2.*/

int Die::inputSides()
{
	cout << "How many sides would you like player die to have?\n";
	cout << "Please enter an even integer value >= 2\n";
	string strSides = "";
	getline(cin, strSides);
	int conSides = 0;
	while (!integerValidation(strSides) 
		|| !sidesValidation(strSides)
		|| !evenValidation(strSides))
	{
		cout << "Invalid input, please enter an even integer value ";
		cout << ">= 2\n";
		strSides = "";
		getline(cin, strSides);
	}
	conSides = stringToInt(strSides);
	return conSides;
}

/*This function allows the user to input select if the created die 
  will be loaded or not. User will select a 1 for yes and 2 for no.
  Input validation will verify that the value is 1 or 2.*/

void Die::makeLoaded()
{
	cout << "Would you like to make this die loaded?\n";
	cout << "Enter 1 for yes and 2 for no\n";
	//perform input validation
	string strLoaded = "";
	getline(cin, strLoaded);
	while (!integerValidation(strLoaded) || !oneTwoValidation(strLoaded))
	{
		cout << "Invalid input, please enter an integer value\n";
		strLoaded = "";
		getline(cin, strLoaded);
	}
	//converting strings to int
	int conLoad = stringToInt(strLoaded);

	if (conLoad == 1)
	{
		this->setLoaded(true);
	}
	else
	{
		this->setLoaded(false);
	}
}

/*This is the roll function for the standard die.  It will return a
  random integer value between 1 and the number if sides on the die.
  The random function needs to be seeded in the main.*/

int Die::roll()
{
	cout << "Using standard roll\n";
	int randRoll = 0;
	randRoll = (rand() % (getSides()) + 1);
	return randRoll;
}