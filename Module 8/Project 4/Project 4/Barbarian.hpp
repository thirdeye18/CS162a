/*********************************************************************
** Program name: Project 4
** Filename: Barbarian.hpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: This is the implementation file for the Barbarian.
********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include <iostream>
#include <string>

#include "Creature.hpp"

using std::string;
using std::cout;
using std::endl;

class Barbarian :
	public Creature
{
private:

	Dice* atkDice;
	Dice* defDice;

public:
	Barbarian();

	virtual ~Barbarian();

	virtual void printName();
	virtual void printType();

	virtual int attack();
	virtual int defense(int);
	virtual void heal();
};

#endif