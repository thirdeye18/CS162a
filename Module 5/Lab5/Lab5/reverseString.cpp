/*********************************************************************
** Program name: Lab5
** Filename: reverseString.cpp
** Author: Justin Hammel
** Date: 5/8/2017
** Description: 
*********************************************************************/

#include "recursiveHeader.hpp"

void reverseString(string inputString)
{
	if (inputString.length() == 0)
	{
		cout << endl << "Done\n";
	}
	else
	{
		cout << inputString[inputString.length() - 1];
		inputString.resize(inputString.length() - 1);
		reverseString(inputString);
	}
	
}