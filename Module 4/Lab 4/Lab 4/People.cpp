/*********************************************************************
** Program name: Lab4
** Filename: People.cpp
** Author: Justin Hammel
** Date: 5/1/2017
** Description:
*********************************************************************/

#include "People.hpp"

People::People()
{
	name = " ";
	age = 0;
}

People::People(const string& nameIn, const int& ageIn, const PersonType& typeIn)
{
	name = nameIn;
	age = ageIn;
	pType = typeIn;
}

People::~People()
{
}

string People::getName()
{
	return name;
}

int People::getAge()
{
	return age;
}

PersonType People::getPtype()
{
	return pType;
}

/*void People::pickPerson()
{

}*/
