/*********************************************************************
** Program name: Project3
** Filename: Vampire.hpp
** Author: Justin Hammel
** Date: 5/15/2017
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
	string name;
	Dice* atkDice;
	Dice* defDice;

public:
	Vampire();
	Vampire(const int&, const int&);

	virtual ~Vampire();

	void printName();

	bool charm();

	virtual int attack();
	virtual int defense(int);

};

#endif