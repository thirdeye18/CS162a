/*********************************************************************
** Program name: Group Project - Rock Paper Scissors
** Author: Faiz Azhar, Justin Hammel, Katherine Isabella, Hao Liu,
**		   and Philip Reed
** Date: 08 May 2017
** Description: The "main" file for a Rock Paper Scissors program.
**				This program allows users to play a virtual game of
**				Rock, Paper, Scissors against a computer using the 
**				RPSGame class and the Tool classes. Any data the user
**				inputs is validated through the use of validation
**				functions.
** Input: User selected tools
** Output: Results of each round of the game
*********************************************************************/

#include "RPSGame.hpp"
#include <ctime> 

int main()
{
	//seeds the rand() function
	srand(time(0));

	//creates a RPSGame object
	RPSGame currentGame;

	//plays the Rock, Paper, Scissors game
	currentGame.playGame();

	return 0;
}


