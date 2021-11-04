/*********************************************************************
** Program name: Project3
** Filename: Medusa.hpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: This is the implementation file for the Medusa.
********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include <iostream>
#include <string>

#include "Creature.hpp"

using std::string;
using std::cout;
using std::endl;

class Medusa :
	public Creature
{
private:
	string name;
	Dice* atkDice;
	Dice* defDice;

public:
	Medusa();
	Medusa(const int&, const int&);

	virtual ~Medusa();

	void printName();

	virtual int attack();
	virtual int defense(int);

};

#endif