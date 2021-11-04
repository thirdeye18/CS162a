/*********************************************************************
** Program name: Project3
** Filename: Dice.hpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: This is the implementation file for my Dice class.
********************************************************************/

#ifndef DICE_HPP
#define DICE_HPP

#include <ctime>
#include <cstdlib>

class Dice
{
private:
	int sides;
	int numDice;

public:
	Dice();
	Dice(int, int);
	~Dice();

	int getNumDice();

	int roll();
	void remDie();
};

#endif