/*********************************************************************
** Program name: Final Project
** Filename: ExitSpace.hpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the implementation file for the derived
**				Exit Space class.
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Dice.hpp"
#include "Space.hpp"

class Player
{
private:
	Dice* playerDice = nullptr;
	Space* currentLocation;
	vector <string> backPack;
	int numDice;
	int maxItems;
	int maxDieItems;
	


public:
	Player();
	Player(const int &numPlayers);
	~Player();
};

#endif