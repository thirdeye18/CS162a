/*********************************************************************
** Program name: Lab5
** Filename: sumArray.cpp
** Author: Justin Hammel
** Date: 5/8/2017
** Description: 
*********************************************************************/

#include "recursiveHeader.hpp"

int sumArray(int* aryIn, int sizeIn)
{
	if (sizeIn == 0)
	{
		return 0;
	}
	else
	{
		return aryIn[sizeIn - 1] += sumArray(aryIn, sizeIn - 1);
	}
}