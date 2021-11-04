/*********************************************************************
** Program name: Project3
** Filename: Creature.hpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: This is the implementation file for my Creature class
********************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>

#include "Dice.hpp"

using std::cout;
using std::endl;

class Creature
{
protected:
	int strength;
	int armour;


public:
	Creature();
	Creature(const int&, const int&);

	virtual ~Creature();

	int getStr();
	int getArm();

	void damage(int);

	virtual void printName() = 0;
	virtual int attack() = 0;
	virtual int defense(int) = 0;
};

#endif