/*********************************************************************
** Program name: Lab7
** Filename: InputValidation.hpp
** Author: Justin Hammel
** Date: 5/22/2017
** Description: This file contains the input validation function 
**				definitions.  There is currently a function that
**				accepts user input as a string and checks to see if 
**				the value is an integer.  A bool value of true is 
**				returned if the input string is an integer and not
**				blank.
*********************************************************************/
#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP

#include <iostream>
#include <string>

using std::string;

bool posIntegerValidation(string inputString);
bool integerValidation(string inputString);
bool floatValidation(string inputString);
bool oneTwoValidation(string inputString);
bool evenValidation(string inputString);
bool notZeroValidation(string inputString);
bool stringValidation(string inputString);

int stringToInt(string inputString);
int stringToFloat(string inputString);

#endif