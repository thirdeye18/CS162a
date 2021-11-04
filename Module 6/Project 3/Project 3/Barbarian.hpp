/*********************************************************************
** Program name: Project3
** Filename: Barbarian.hpp
** Author: Justin Hammel
** Date: 5/15/2017
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
	string name;
	Dice* atkDice;
	Dice* defDice;

public:
	Barbarian();
	Barbarian(const int&, const int&);

	virtual ~Barbarian();

	void printName();

	virtual int attack();
	virtual int defense(int);

};

#endif