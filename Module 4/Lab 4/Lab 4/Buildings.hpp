/*********************************************************************
** Program name: Lab4
** Filename: Buildings.hpp
** Author: Justin Hammel
** Date: 5/1/2017
** Description: This is the implementation file for my Buildings
**				class.
*********************************************************************/

#ifndef BUILDINGS_HPP
#define BUILDINGS_HPP

#include <string>

using std::string;

class Buildings
{
private:
	string buildName;
	int size;
	string address;

public:
	Buildings();
	Buildings(string, int, string);
	~Buildings();

	string getBuildName();
	int getSize();
	string getAddress();
};

#endif