/*********************************************************************
** Program name: Lab 9
** Filename: InputValidation.hpp
** Author: Justin Hammel
** Date: 6/4/2017
** Description: This file contains the input validation function 
**				definitions.  Documentatiton for each type of 
**				validation precedes the applicable function.
*********************************************************************/
#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP

#include <string>
#include <iostream>

using std::string;
using std::stoi;
using std::stof;
using std::cout;
using std::endl;


bool posIntegerValidation(string inputString);

bool integerValidation(string inputString);

bool floatValidation(string inputString);

bool rangeValidation(int input, int low, int high);

bool oneValidation(string inputString);

bool evenValidation(string inputString);

bool notZeroValidation(string inputString);

bool stringValidation(string inputString);

bool txtValidation(string inputString);

int stringToInt(string inputString);
int stringToFloat(string inputString);

#endif