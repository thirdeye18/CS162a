/*********************************************************************
** Program name: Lab5
** Filename: recursiveHeader.hpp
** Author: Justin Hammel
** Date: 5/8/2017
** Description: Header file for the recursive functions reverseString,
**				sumArray, and triNumber.  Contains the function
**				prototypes for each of these functions.
*********************************************************************/

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

#ifndef RECURSIVEHEADER_HPP
#define RECURSIVEHEADER_HPP

void reverseString(string);
int sumArray(int *, int);
int triNum(int);

#endif 