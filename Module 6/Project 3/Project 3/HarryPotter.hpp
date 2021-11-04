/*********************************************************************
** Program name: Project3
** Filename: HarryPotter.hpp
** Author: Justin Hammel
** Date: 5/15/2017
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
	string name;
	int lifeCounter;
	Dice* atkDice;
	Dice* defDice;

public:
	HarryPotter();
	HarryPotter(const int&, const int&);

	virtual ~HarryPotter();

	void printName();

	void hogwarts();

	virtual int attack();
	virtual int defense(int);

};

#endif