/*********************************************************************
** Program name: Project 4
** Filename: BlueMen.hpp
** Author: Justin Hammel
** Date: 5/29/2017
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

	int dmgCheck;
	Dice* atkDice;
	Dice* defDice;

public:
	BlueMen();

	virtual ~BlueMen();

	virtual void printName();
	virtual void printType();

	void mob();

	virtual int attack();
	virtual int defense(int);
	virtual void heal();

};

#endif