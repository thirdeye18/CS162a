/*********************************************************************
** Program name: Lab4
** Filename: main.cpp
** Author: Justin Hammel
** Date: 5/1/2017
** Description: This is the main for testing the University program 
				and associated classes.
*********************************************************************/

#include <iostream>
#include <string>
#include <ctime>

#include "Menu.hpp"
#include "University.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main()
{
	//seeding rand
	srand((unsigned int)time(NULL));

	//Creating Menu object and printing menu
	Menu currentMenu;
	//currentMenu.clearScreen();

	University uni1("Oregon State University", 2, 2);
	uni1.addBuildings();
	uni1.addPeople();

	int choice = 0;
	while (choice != 4)
	{
		cout << endl;
		currentMenu.printMenu();
		choice = currentMenu.userChoice();
		//Print building Info
		if (choice == 1) 
		{
			currentMenu.clearScreen();
			uni1.uniPrint();
		}
		//Print people info
		else if (choice == 2) 
		{
			currentMenu.clearScreen();
			uni1.peoplePrint();
		}
		//Choose person for work
		else if (choice == 3) 
		{
			//Printing out list of people for menu
			currentMenu.clearScreen();
			int personChoice = 0;
			int exitPeople = 0;
			exitPeople = uni1.getPeopleCount() + 1;
			cout << exitPeople << endl;

			uni1.namePrint();
			cout << exitPeople << ". Return to the previous ";
			cout << "menu\n" << endl;
			cout << "Please select the person to display work hours for.\n";
			cout << "Please enter a number next to the person ";
			cout << "you would like to display information for.\n";

			while (personChoice != exitPeople)
			{
				personChoice = currentMenu.userChoice();

				if (personChoice < 0)
				{
					cout << "Invalid choice\n";
					cout << "Please enter a number next to the person ";
					cout << "you would like to display information for.\n";
				}
				else if (personChoice > exitPeople && personChoice != exitPeople)
				{
					cout << "Invalid choice\n";
					cout << "Please enter a number next to the person ";
					cout << "you would like to display information for.\n";
				}
				else if (personChoice < exitPeople)
				{
					cout << "Computing hours\n";
					
					int maxHours = 40;
					People** workPtr = uni1.getStoredPeople();
					workPtr[personChoice - 1]->doWork(maxHours);
				}
			}
		}
		//Exit program
		else if (choice == 4)
		{
			cout << "Exiting the program\n";
		}
		else
		{
			cout << "Invalid menu choice! Please try again\n";
		}
	}
	return 0;
}