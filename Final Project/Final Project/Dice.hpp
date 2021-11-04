/*********************************************************************
** Program name: Final Project
** Filename: Dice.hpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the implementation file for my Dice class.
********************************************************************/

#ifndef DICE_HPP
#define DICE_HPP

#include <ctime>
#include <cstdlib>
#include <vector>

using std::vector;

class Dice
{
private:
	int sides;
	int numDice;
	vector <char> diceResults;

public:
	Dice();
	Dice(const int &sidesIn, const int &numIn);
	~Dice();

	int getNumDice();

	void roll();
	void remDie();
	char convertRoll(int rolledNum);
};

#endif