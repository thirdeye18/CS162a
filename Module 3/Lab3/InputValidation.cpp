/*********************************************************************
** Program name: Project1
** Filename: InputValidation.cpp
** Author: Justin Hammel
** Date: 4/17/2017
** Description: This is my main for running general programs and
**				testing.
********************************************************************/

#include <iostream>
#include <string>

#include "InputValidation.hpp"

using std::string;
using std::stoi;

/*********************************************************************
** This function provides integer input validation.  A user input 
** string is passed to the function.  The function steps through the 
** string and checks if the value in each place is a number.  A bool 
** value of true is returned if the input string is an integer and 
** not blank, otherwise a value of false is returned.
*********************************************************************/
bool integerValidation(string inputString)
{
	if (inputString.length() == 0)
		return false;
	for (size_t i = 0; i < inputString.length(); i++)
		if (!isdigit(inputString[i]))
		{
			return false;
		}
	return true;
}

/*********************************************************************
** This function provides validates an integer >1 is the value  
** stored for the integer passed to it.  Returns true if the passed  
** value is >1, or false if not. 
*********************************************************************/
bool sidesValidation(string inputString)
{
	int input = stoi(inputString);
	if (input > 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool oneTwoValidation(string inputString)
{
	int input = stoi(inputString);
	if (input == 1 || input == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool evenValidation(string inputString)
{
	int input = stoi(inputString);
	if (input % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*Function to verify that the entered value is greater than 0*/

bool notZeroValidation(string inputString)
{
	int input = stoi(inputString);
	if (input > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*********************************************************************
** This function converts user input strings to integer values
** following integer input validation.  String is passed to the
** function, converted to an integer and retuned to the callling 
** program.
*********************************************************************/
int stringToInt(string inputString)
{
	int intInput = stoi(inputString);
	return intInput;
}
