/*********************************************************************
** Program name: Project 4
** Filename: Medusa.hpp
** Author: Justin Hammel
** Date: 5/29/2017
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

	Dice* atkDice;
	Dice* defDice;

public:
	Medusa();

	virtual ~Medusa();

	virtual void printName();
	virtual void printType();

	virtual int attack();
	virtual int defense(int);
	virtual void heal();

};

#endif