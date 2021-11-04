/*********************************************************************
** Program name: Lab 8
** Filename: InputValidation.cpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: This is my main for running general programs and
**				testing.
********************************************************************/

#include <iostream>
#include <string>

#include "InputValidation.hpp"

using std::string;
using std::stoi;
using std::stof;
using std::cout;
using std::endl;

/*********************************************************************
** This function provides integer input validation.  A user input 
** string is passed to the function.  The function steps through the 
** string and checks if the value in each place is a number.  A bool 
** value of true is returned if the input string is an integer and 
** not blank, otherwise a value of false is returned.  Only works 
** positive integers.
*********************************************************************/

bool posIntegerValidation(string inputString)
{
	if (inputString.length() == 0)
	{
		return false;
	}
	for (size_t i = 0; i < inputString.length(); i++)
		if (!isdigit(inputString[i]))
		{
			return false;
		}
	return true;
}

/*********************************************************************
** This function provides integer input validation.  A user input
** string is passed to the function.  The function steps through the
** string and checks if the value in each place is a number.  A bool
** value of true is returned if the input string is an integer and
** not blank, otherwise a value of false is returned.  Works with 
** negative integers.
*********************************************************************/

bool integerValidation(string inputString)
{
	if (inputString.length() == 0)
	{
		return false;
	}

	for (size_t i = 0; i < inputString.length(); i++)
		if (!isdigit(inputString[i]) && inputString[i] != 45)
		{
			return false;
		}
	return true;
}

/*********************************************************************
** This function provides float input validation.  A user input
** string is passed to the function.  The function steps through the
** string and checks if the value in each place are a number, or a period.  A bool
** value of true is returned if the input string is a float and
** not blank, otherwise a value of false is returned.
*********************************************************************/

bool floatValidation(string inputString)
{
	if (inputString.length() == 0)
	{
		return false;
	}
	//setup counter to make sure only one period in input stream
	int decimalCount = 0;
	for (size_t i = 0; i < inputString.length(); i++)
	{ 
		if (inputString[i] == '.')
		{
			decimalCount += 1;
		}
		if (!isdigit(inputString[i]) && inputString[i] != '.')
		{
			return false;
		}
		if (decimalCount > 1)
		{
			return false;
		}
	}
	return true;
}

/*********************************************************************
** This function provides validates an integer >1 is the value  
** stored for the integer passed to it.  Returns true if the passed  
** value is >1, or false if not. 
*********************************************************************/

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

/*Function to verify that a string contains useable data.  Ensures that
  string is not just spaces, or enter.*/

bool stringValidation(string inputString)
{
	//checking that string is not blank
	if (inputString.length() == 0)
	{
		return false;
	}
	
	//checking that string is not enter
	if (inputString[0] == 13)
	{
		return false;
	}

	//checking for all spaces
	size_t spaceCount = 0;
	for (size_t i = 0; i < inputString.length(); i++)
	{
		if (inputString[i] == 32)
		{
			spaceCount += 1;
		}
	}
	if (spaceCount == inputString.length())
	{
		return false;
	}

	return true;
}

/*Function to verify that a valid text filename has been entered.  
Ensures that string is not just spaces, or enter. File name 
should be in the format name.txt.*/

bool txtValidation(string inputString)
{
	//checking that string is not blank
	if (inputString.length() == 0)
	{
		return false;
	}

	//checking that string is not enter
	if (inputString[0] == 13)
	{
		return false;
	}

	//setup counter to make sure only one period in input stream
	int decimalCount = 0;
	for (size_t i = 0; i < inputString.length(); i++)
	{
		if (inputString[i] == '.')
		{
			decimalCount += 1;
		}
		if (decimalCount > 1)
		{
			return false;
		}
	}

	//checking for all spaces
	size_t spaceCount = 0;
	for (size_t i = 0; i < inputString.length(); i++)
	{
		if (inputString[i] == 32)
		{
			spaceCount += 1;
		}
	}
	if (spaceCount == inputString.length())
	{
		return false;
	}

	//checking that the file name ends in .txt
	int lastFour = 0;
	lastFour = inputString.length() - 4;
	if (inputString[lastFour] != '.')
	{
		return false;
	}
	if (inputString[lastFour + 1] != 't')
	{
		return false;
	}
	if (inputString[lastFour + 2] != 'x')
	{
		return false;
	}
	if (inputString[lastFour + 3] != 't')
	{
		return false;
	}
	return true;
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

/*********************************************************************
** This function converts user input strings to float values
** following float input validation.  String is passed to the
** function, converted to an float and retuned to the callling
** program.
*********************************************************************/
int stringToFloat(string inputString)
{
	float floatInput = stof(inputString);
	return floatInput;
}