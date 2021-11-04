/*********************************************************************
** Program name: Project 3
** Filename: main.cpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: Main for the implementation of my Creature and  
**				Creature derived classes.  This will create the menu  
**				to allow sellecting the two creatures to fight, or  
**				exiting the program. 
*********************************************************************/

#include <iostream>
#include <string>
//#include<vld.h>

#include "InputValidation.hpp"
#include "Menu.hpp"
#include "Fight.hpp"
#include "Creature.hpp"
#include "Dice.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

const int MENU_OPTIONS = 6;

int main()
{
	//seeding rand for dice and randomStart
	srand((unsigned)time(NULL));

	Menu currentMenu;

	int choice = 0;
	int fighters = 0;
	Creature* creature1,* creature2;
	creature1 = creature2 = NULL;
	Fight* currentFight;
	currentFight = NULL;

	while (choice != 6)
	{
		cout << endl;
		cout << "Select your two fighters.\n";
		cout << "Individual fighters may be selected multiple times\n";
		currentMenu.printMenu();
		choice = currentMenu.userChoice();

		//Strength and armor variable for different creatures
		int vStr = 18, vArm = 1,
		    bStr = 12, bArm = 0,
			bmStr = 12, bmArm = 3,
		    mStr = 8, mArm = 3,
		    hpStr = 10, hpArm = 0;

		switch (choice)
		{
		case 1://Vampire

			currentMenu.clearScreen();
			fighters += 1;
			cout << "Creature " << fighters << " is a Vampire.\n";
			if (fighters == 1)
			{
				creature1 = new Vampire(vStr, vArm);
			}
			else
			{
				creature2 = new Vampire(vStr, vArm);
			}
			break;

		case 2://Barbarian

			currentMenu.clearScreen();
			fighters += 1;
			cout << "Creature " << fighters << " is a Barbarian.\n";
			if (fighters == 1)
			{
				creature1 = new Barbarian(bStr, bArm);
			}
			else
			{
				creature2 = new Barbarian(bStr, bArm);
			}
			break;

		case 3://Blue Men

			currentMenu.clearScreen();
			fighters += 1;
			cout << "Creature " << fighters << " is the Blue Men.\n";
			if (fighters == 1)
			{
				creature1 = new BlueMen(bmStr, bmArm);
			}
			else
			{
				creature2 = new BlueMen(bmStr, bmArm);
			}
			break;

		case 4://Medusa

			currentMenu.clearScreen();
			fighters += 1;
			cout << "Creature " << fighters << " is a Medusa.\n";
			if (fighters == 1)
			{
				creature1 = new Medusa(mStr, mArm);
			}
			else
			{
				creature2 = new Medusa(mStr, mArm);
			}
			break;

		case 5://Harry Potter

			currentMenu.clearScreen();
			fighters += 1;
			cout << "Creature " << fighters << " is Harry Potter.\n";
			if (fighters == 1)
			{
				creature1 = new HarryPotter(hpStr, hpArm);
			}
			else
			{
				creature2 = new HarryPotter(hpStr, hpArm);
			}
			break;

		case 6://Exit

			cout << "Exiting the program\n";
			break;

		default://invalid menu option

			cout << "Invalid menu choice! Please try again\n";
			currentMenu.clearScreen();

		}
		if (fighters == 2)
		{
			cout << "Preparing for battle!\n";

			currentFight = new Fight(creature1, creature2);

			int round = 1;
			while (creature1->getStr() > 0 && creature2->getStr() > 0)
			{
				currentFight->combat(round);
			}

			//display the fight winner
			if (creature1->getStr() > 0)
			{
				cout << "Creature # 1 ";
				creature1->printName();
				cout << " Wins!\n";
			}

			if (creature2->getStr() > 0)
			{
				cout << "Creature # 2 ";
				creature2->printName();
				cout << " Wins!\n";
			}

			delete creature1;
			delete creature2;
			creature1 = creature2 = NULL;

			//option to play again or exit
			int replayChoice = 0;
			while (replayChoice == 0)
			{
				cout << "Would you like to play again, or exit the game?\n";
				cout << "Enter 1 to play again, or 2 to exit.\n";
				replayChoice = currentMenu.userChoice();
				if (replayChoice == 1)
				{
					choice = 0;
					fighters = 0;
				}
				else if (replayChoice == 2)
				{
					choice = 6;
					cout << "Exiting the program\n";
				}
				else
				{
					cout << "Enter 1 to play again, or 2 to exit.\n";
					replayChoice = 0;
				}
			}
			delete currentFight;
			currentFight = NULL;
		}
	}

	delete creature1;
	delete creature2;
	creature1 = creature2 = NULL;
	delete currentFight;
	currentFight = NULL;

	return 0;
}
