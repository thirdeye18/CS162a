/*********************************************************************
** Program name: Project3
** Filename: BlueMen.hpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: This is the implementation file for the Blue Men.
********************************************************************/

#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include <iostream>
#include <string>

#include "Creature.hpp"

using std::string;
using std::cout;
using std::endl;

class BlueMen :
	public Creature
{
private:
	string name;
	int dmgCheck;
	Dice* atkDice;
	Dice* defDice;

public:
	BlueMen();
	BlueMen(const int&, const int&);

	virtual ~BlueMen();

	void printName();

	void mob();

	virtual int attack();
	virtual int defense(int);

};

#endif