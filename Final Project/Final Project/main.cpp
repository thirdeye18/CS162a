/*********************************************************************
** Program name: Final Project
** Filename: main.cpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: Main for the implementation of my Escape the Curse of     
**				the Temple Game. This will create the menu for 
**				setting up and starting the game. 
*********************************************************************/

//Enable or disable leak check library based on system
#if defined(_WIN32)
#include <vld.h>
#endif 

#include <iostream>
#include <ctime>

#include "Game.hpp"

const int MENU_OPTIONS = 3;

int main()
{
	//seeding rand for dice and room parameters
	srand(time(NULL));

	//generating the main menu
	Menu mainMenu("MainMenuOptions.txt");

	//choice selection for user
	int choice = 0;

	//determine if the game is setup
	bool setup = false;

	//Creating object pointers for game
	Game* currentGame = nullptr;

	while (choice != MENU_OPTIONS)
	{
		mainMenu.printMenu();
		cout << "Please select an option from the menu.\n";
		choice = mainMenu.userChoice(MENU_OPTIONS);
				
		switch (choice)
		{
		case 1://Select number of players, currently only allows 1
		{
			mainMenu.clearScreen();
			
			//getting number of players from the user
			cout << "Please enter a positive integer for the number\n";
			cout << "of players for the game (only 1 allowed).\n";
			int players = 0;
			players = mainMenu.userChoice(1);
			cout << endl;

			//getting difficulty from the user
			cout << "Please enter a positive integer for difficulty.\n";
			cout << "1 - Easy, 2 - Medium, 3 - Hard\n";
			int difficulty = 0;
			difficulty = mainMenu.userChoice(3);
			cout << endl;

			currentGame = new Game(players, difficulty);

			setup = true;

			break;
		}

		case 2://Start game
		{
			
			mainMenu.clearScreen();
			
			if (!setup)
			{
				cout << "Please run game setup first with option 1.\n";
				break;
			}

			currentGame->playGame();

			//setting up to allow a new game to play
			delete currentGame;
			currentGame = nullptr;
			setup = false;

			break;
		}

		case 3://Exit

			cout << "Exiting the program\n";

			//cleaning up
			delete currentGame;
			currentGame = nullptr;

			break;

		default://invalid menu option

			cout << "Invalid menu choice! Please try again\n";
			mainMenu.clearScreen();

		}

	}

	return 0;
}