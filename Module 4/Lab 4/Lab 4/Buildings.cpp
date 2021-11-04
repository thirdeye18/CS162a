/*********************************************************************
** Program name: Lab4
** Filename: Buildings.cpp
** Author: Justin Hammel
** Date: 5/1/2017
** Description:
*********************************************************************/

#include "Buildings.hpp"



Buildings::Buildings()
{
	buildName = " ";
	size = 0;
	address = " ";
}

Buildings::Buildings(string bName, int bSize, string bAddress)
{
	buildName = bName;
	size = bSize;
	address = bAddress;
}


Buildings::~Buildings()
{
}

string Buildings::getBuildName()
{
	return buildName;
}

int Buildings::getSize()
{
	return size;
}

string Buildings::getAddress()
{
	return address;
}
