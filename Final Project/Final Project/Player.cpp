/*********************************************************************
** Program name: Final Project
** Filename: Player.cpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: Player class for my Escape the Curse of the Temple 
**				Game. Class is used to hold the players pack objects 
**				and control movement in the game.
*********************************************************************/

#include "Player.hpp"

/*Constructors*/

Player::Player()
{
}

Player::Player(const int &numPlayers)
{
	maxItems = 1;
	maxDieItems = numDice;
	numDice = 7;
	playerDice = new Dice(6, numDice);
}

/*Destructor*/

Player::~Player()
{
	delete playerDice;
	playerDice = nullptr;
}
