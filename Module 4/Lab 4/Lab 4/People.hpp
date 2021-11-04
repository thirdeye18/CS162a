/*********************************************************************
** Program name: Lab4
** Filename: People.hpp
** Author: Justin Hammel
** Date: 5/1/2017
** Description: This is the implementation file for my People
**				class.
*********************************************************************/

#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include <string>

enum PersonType { STUDENT, INSTRUCTOR};

using std::string;

class People
{
protected:
	string name;
	int age;
	int hoursWorked;
	PersonType pType;

public:
	People();
	People(const string&, const int&, const PersonType&);
	virtual ~People();

	virtual void doWork(int) = 0;
	virtual float getInfo() = 0;

	string getName();
	int getAge();
	PersonType getPtype();

	//void pickPerson();
};

#endif