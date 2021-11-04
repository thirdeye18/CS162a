/*********************************************************************
** Program name: Project 4
** Filename: HarryPotter.hpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: This is the implementation file for Harry Potter.
********************************************************************/

#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

#include <iostream>
#include <string>

#include "Creature.hpp"

using std::string;
using std::cout;
using std::endl;

class HarryPotter :
	public Creature
{
private:

	int lifeCounter;
	Dice* atkDice;
	Dice* defDice;

public:
	HarryPotter();

	virtual ~HarryPotter();

	virtual void printName();
	virtual void printType();

	void hogwarts();

	virtual int attack();
	virtual int defense(int);
	virtual void heal();

};

#endif