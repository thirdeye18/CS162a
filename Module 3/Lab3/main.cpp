/*********************************************************************
** Program name: Lab3
** Filename: main.cpp
** Author: Justin Hammel
** Date: 4/24/2017
** Description: This is my main for running the game of War using 
**		dice for Lab 3.  Further documentation for functions
**		is shown as comments before associated functions.

*********************************************************************/
#include <iostream>
#include <memory>

#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Menu.hpp"
#include "InputValidation.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;
using std::dynamic_pointer_cast;

int getRoundsInput();

int main()
{
	//seeding rand
	srand((unsigned int)time(NULL));

	//Creating Menu object and printing menu
	Menu currentMenu;
	currentMenu.clearScreen();

	//check for if both dice have been created
	bool player1DieExists = false;
	bool player2DieExists = false;
	WhichLoaded thisGame = NONE;

	int choice = 0;
	while (choice != 4)
	{
		
		//create initial Die object
		shared_ptr<Die> player1 = make_shared<Die>();
		shared_ptr<Die> player2 = make_shared<Die>();
		shared_ptr<LoadedDie> player1Ld = make_shared<LoadedDie>();
		shared_ptr<LoadedDie> player2Ld = make_shared<LoadedDie>();
		
		currentMenu.printMenu();
		choice = currentMenu.userChoice();
		
		//Play game option
		if (choice == 1) 
		{
			currentMenu.clearScreen();

			if (!player1DieExists || !player2DieExists)
			{
				cout << "Player dice not created";
				cout << " please do this before starting game.\n";
			}
			else
			{
				//testing to see how many sides 
				cout << player1->getSides() << " sides player 1\n";
				cout << player2->getSides() << " sides player 2\n";
				cout << player1Ld->getSides() << " sides player 1 Loaded\n";
				cout << player2Ld->getSides() << " sides player 2 Loaded\n";
				
				//fill vector with possible die objects
				vector<shared_ptr<Die>> gameDice
					{player1, player2, player1Ld, player2Ld};
				
				//get rounds input from the user
				int currentRounds = 0;
				currentRounds = getRoundsInput();
				
				//create current game with unique pointer				
				unique_ptr<Game> currentGame(new Game(currentRounds));

				currentGame->play(gameDice, thisGame);
	
				cout << "Game played for " << currentRounds;
				cout << " rounds.\n";
				cout << "Player 1 Final score - ";
				cout << currentGame->getPlayer1Score() << endl;
				cout << "Playing with a ";
				cout << player1->getSides() << " sided ";
				if (player1->getLoaded())
				{
					cout << "loaded die \n";
				}
				else
				{
					cout << "regular die \n";
				}
				cout << "Player 2 Final score - ";
				cout << currentGame->getPlayer2Score() << endl;
				cout << "Playing with a ";
				cout << player2->getSides() << " sided ";
				if (player2->getLoaded())
				{
					cout << "loaded die \n";
				}
				else
				{
					cout << "regular die \n";
				}
				if (currentGame->getPlayer1Score() >
					currentGame->getPlayer2Score())
				{
					cout << "Player 1 Wins\n";
				}
				else if (currentGame->getPlayer1Score() <
					currentGame->getPlayer2Score())
				{
					cout << "Player 2 Wins\n";
				}
				else
				{
					cout << "Game is a draw.\n";
				}
				cout << "Press any key to continue\n";
				cin.get();
				cin.ignore();
				currentMenu.clearScreen();
				currentMenu.printMenu();
			}
		}
		//Set up player 1 die
		if (choice == 2) 
		{
			currentMenu.clearScreen();
			
			//new shared pointer for setting up p1Die
			shared_ptr<Die> ptrPlay1 = make_shared<Die>
				(ptrPlay1->inputSides());
			player1 = ptrPlay1;
			player1DieExists = true;

			//determine if created die will be loaded
			player1->makeLoaded();

			if (player1->getLoaded())
			{
				int loadSides = player1->getSides();
				shared_ptr<LoadedDie>ptrLoad1 = make_shared<LoadedDie>(loadSides);
				player1Ld = ptrLoad1;
				if (thisGame == NONE)
				{
					thisGame = P1LOADED;
				}
				if (thisGame == P2LOADED)
				{
					thisGame = BOTH;
				}

				currentMenu.clearScreen();
				cout << "Player 1 die created\n";
				cout << endl << endl;
				currentMenu.printMenu();
			}
		}
		//Set up player 2 die
		if (choice == 3) 
		{
			currentMenu.clearScreen();
			
			//new shared pointer for setting up p1Die
			shared_ptr<Die> ptrPlay2 = make_shared<Die>
				(ptrPlay2->inputSides());
			player2 = ptrPlay2;
			player2DieExists = true;

			//determine if created die will be loaded
			player2->makeLoaded();

			if (player2->getLoaded())
			{
				int loadSides = player2->getSides();
				shared_ptr<LoadedDie>ptrLoad2 = make_shared<LoadedDie>(loadSides);
				player2Ld = ptrLoad2;
				if (thisGame == NONE)
				{
					thisGame = P2LOADED;
				}
				if (thisGame == P1LOADED)
				{
					thisGame = BOTH;
				}
			}

			currentMenu.clearScreen();
			cout << "Player 2 die created\n";
			cout << endl << endl;
			currentMenu.printMenu();

			//reset Die object smart Pointer for new game
			player1.reset();
			player2.reset();
			player1Ld.reset();
			player2Ld.reset();
		}
		//Exit the program
		if (choice == 4) 
		{
			cout << "Exiting the game.\n";
		}
		if (choice > 4 || choice < 0)
		{
			cout << "Invalid menu option\n";
		}
	}
	return 0;
}	

int getRoundsInput()
{
	cout << "How many rounds would you like to play?\n";
	cout << "Please enter an integer value greater than 0\n";
	string strRounds = "";
	getline(cin, strRounds);

	int conRounds = 0;
	while (!integerValidation(strRounds) ||
		!notZeroValidation(strRounds))
	{
		cout << "Invalid input, please enter an integer value > 0\n";
		strRounds = "";
		getline(cin, strRounds);
	}
	conRounds = stringToInt(strRounds);

	return conRounds;
}
