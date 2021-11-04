/*********************************************************************
** Program name: Lab4
** Filename: Buildings.hpp
** Author: Justin Hammel
** Date: 5/1/2017
** Description: This is the implementation file for my Buildings
**				class.
*********************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "People.hpp"
#include "Buildings.hpp"
#include "InputValidation.hpp"


using std::string;
using std::cout;
using std::endl;
using std::fstream;
using std::ios;
using std::setprecision;
using std::fixed;
using std::showpoint;

class University
{
private:
	string uniName;
	int buildingCount;
	int peopleCount;

	People** storedPeople;
	Buildings* storedBuildings;

public:
	University();
	University(string, int, int);
	~University();

	int getPeopleCount();
	People** getStoredPeople();

	void uniPrint();
	void peoplePrint();
	void namePrint();
	void addBuildings();
	void addPeople();
};

#endif