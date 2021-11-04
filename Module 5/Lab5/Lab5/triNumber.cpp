/*********************************************************************
** Program name: Lab5
** Filename: triNumber.cpp
** Author: Justin Hammel
** Date: 5/8/2017
** Description: 
*********************************************************************/

#include "recursiveHeader.hpp"

int triNum(int n)
{
	if (n == 0)
	{
		return n;
	}
	else
	{
		return n += triNum(n - 1);
	}
}