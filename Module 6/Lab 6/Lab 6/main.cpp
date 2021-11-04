/*********************************************************************
** Program name: Lab 6
** Filename: main.cpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: Main for the implementation of my Linked structure 
**				Lab.  This will create the menu to allow sellecting 
**				manipulating the linked structures, or exiting the 
**				program.
*********************************************************************/

#include <iostream>
#include <string>

#include "InputValidation.hpp"
#include "Menu.hpp"
#include "IntList.hpp"

int main()
{
	Menu currentMenu;

	int choice = 0;
	IntList newList;

	cout << "Welcome to the linked list!\n" << endl;
	
	while (choice != 6)
	{
		cout << endl;
		cout << "Select an option from the menu.\n" << endl;
		currentMenu.printMenu();
		choice = currentMenu.userChoice();

		//initializing variables to use in the switch statements
		string strAdd;
		int add;

		switch (choice)
		{
		case 1://Add new node to head (front)

			currentMenu.clearScreen();

			//getting new value for list
			strAdd = "";
			add = 0;
			while (!posIntegerValidation(strAdd))
			{
				cout << "Please enter a positive integer.\n";
				getline(cin, strAdd);
				if (!posIntegerValidation(strAdd))
				{
					cout << "Please enter a positive integer.\n";
					strAdd = "";
					getline(cin, strAdd);
				}
			}
			add = stringToInt(strAdd);

			//adding new value to head of list
			newList.addFront(add);
			
			//Printing the list
			newList.display();

			break;

		case 2://Add new node to tail (end)

			currentMenu.clearScreen();

			//getting new value for list
			strAdd = "";
			add = 0;
			while (!posIntegerValidation(strAdd))
			{
				cout << "Please enter a positive integer.\n";
				getline(cin, strAdd);
				if (!posIntegerValidation(strAdd))
				{
					cout << "Please enter a positive integer.\n";
					strAdd = "";
					getline(cin, strAdd);
				}
			}
			add = stringToInt(strAdd);

			//adding new value to tail of list
			newList.addEnd(add);

			//Printing the list
			newList.display();

			break;

		case 3://Delete from head

			currentMenu.clearScreen();
			newList.removeFront();
			newList.display();

			break;

		case 4://Delete from tail

			currentMenu.clearScreen();
			newList.removeEnd();
			newList.display();

			break;

		case 5://Traverse list reversely

			currentMenu.clearScreen();
			newList.reverseDisplay();

			break;

		case 6://Exit

			cout << "Exiting the program\n";
			break;

		default://invalid menu option

			cout << "Invalid menu choice! Please try again\n";
			currentMenu.clearScreen();

		}
	}

	return 0;
}
