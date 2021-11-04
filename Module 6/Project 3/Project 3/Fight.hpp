/*********************************************************************
** Program name: Project3
** Filename: Fight.hpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: This is the implementation file for the Fight class.
********************************************************************/

#ifndef FIGHT_HPP
#define FIGHT_HPP

#include <iostream>

#include "Creature.hpp"

using std::cout;
using std::endl;

class Fight
{
private:
	int turn;
	Creature* creatArry[2];

public:
	Fight();
	Fight(Creature* , Creature* );

	~Fight();

	void randomStart();
	void combat(int&);
};

#endif