/*********************************************************************
** Program name: Project 4
** Filename: main.cpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: Main for the implementation of my tournamnet style  
**				fight for the Creature and Creature derived classes.  
**				This will create the menu for starting or quitting. 
*********************************************************************/

#include <iostream>
#include <string>
//#include<vld.h>

#include "Tournament.hpp"

const int MENU_OPTIONS = 2;

int main()
{
	//seeding rand for dice and randomStart
	srand((unsigned)time(nullptr));

	//generating the main menu
	Menu mainMenu("MainMenuOptions.txt");

	int choice = 0;

	Tournament* currentTour;
	currentTour = nullptr;

	while (choice != MENU_OPTIONS)
	{
		mainMenu.printMenu();
		cout << "Please select an option from the menu.\n";
		choice = mainMenu.userChoice();

		switch (choice)
		{
		case 1://Start game
		{
			int fighters = 0;

			cout << endl << "Starting the tournament!\n" << endl;
			cout << "How many creatures would you like on each team?\n";
			cout << "Please enter a postitve integer value for the team size\n";
			fighters = mainMenu.userChoice();

			//creating object for the current tournament
			currentTour = new Tournament(fighters);

			cout << endl;
			cout << "Moving to creature selection for the human ";
			cout << "and CPU teams.\nCreatures will fight in the ";
			cout << "order they are added to a team.\nThe Human ";
			cout << "player selects their team first, followed by ";
			cout << "the user selecting the CPU's team members.\n";
			cout << "The user will also be prompted to enter a ";
			cout << "name for each creature being added to a team.\n";
			cout << "The same type of creature can be selected ";
			cout << "multiple times.\n";
			cout << endl;

			//adding creatures to the team lists
			currentTour->fillHumanQueue();
			currentTour->fillCPUQueue();

			currentTour->runTournament();

			break;
		}
		case 2://Exit

			cout << "Exiting the program\n";
			break;

		default://invalid menu option

			cout << "Invalid menu choice! Please try again\n";
			mainMenu.clearScreen();

		}
	}

	delete currentTour;
	currentTour = nullptr;

	return 0;
}
