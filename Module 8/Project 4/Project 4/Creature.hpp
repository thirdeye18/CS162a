/*********************************************************************
** Program name: Project 4
** Filename: Creature.hpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: This is the implementation file for my Creature class
********************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <string>

#include "Dice.hpp"
#include "InputValidation.hpp"

using std::cout;
using std::endl;
using std::string;
using std::cin;

//Strength and armor variable for different creatures
const int VAMP_STR = 18, VAMP_ARM = 1,
	BARB_STR = 12, BARB_ARM = 0,
	BLUE_STR = 12, BLUE_ARM = 3,
	MED_STR = 8, MED_ARM = 3,
	HP_STR = 10, HP_ARM = 0;

class Creature
{
protected:
	int strength;
	int armour;
	string name;
	string type;


public:
	Creature();
	Creature(const int&, const int&);

	virtual ~Creature();

	int getStr();
	int getArm();

	void damage(int);
	void assignName();

	virtual void heal() = 0;
	virtual void printName() = 0;
	virtual void printType() = 0;
	virtual int attack() = 0;
	virtual int defense(int) = 0;
};

#endif