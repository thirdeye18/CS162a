/*********************************************************************
** Program name: Project 4
** Filename: Vampire.hpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: This is the implementation file for the Vampire.
********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include <iostream>
#include <string>

#include "Creature.hpp"

using std::string;
using std::cout;
using std::endl;

class Vampire :
	public Creature
{
private:

	Dice* atkDice;
	Dice* defDice;

public:
	Vampire();

	virtual ~Vampire();

	virtual void printName();
	virtual void printType();

	bool charm();

	virtual int attack();
	virtual int defense(int);
	virtual void heal();

};

#endif