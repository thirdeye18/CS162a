/*********************************************************************
** Program name: Lab 7
** Filename: main.cpp
** Author: Justin Hammel
** Date: 5/22/2017
** Description: Main for the implementation of my Queue linked list 
**				Lab.  This will create the menu to allow sellecting 
**				manipulating the linked structures, or exiting the 
**				program.
*********************************************************************/

#include <iostream>
#include <string>
//#include <vld.h>

#include "InputValidation.hpp"
#include "Menu.hpp"
#include "Queue.hpp"

int main()
{
	const int MENU_CHOICES = 5;

	Menu currentMenu;

	int choice = 0;
	Queue newList;

	cout << "Welcome to the Queue, ";
	cout << "a doubly - linked circular structure!\n" << endl;
	
	while (choice != MENU_CHOICES)
	{
		cout << endl;
		cout << "Select an option from the menu.\n" << endl;
		currentMenu.printMenu();
		choice = currentMenu.userChoice();

		//initializing variables to use in the switch statements
		string strAdd;
		int add;
		int dispFront = 0;

		switch (choice)
		{
		case 1://Add new node to tail (end)

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
			newList.addBack(add);

			//Printing the list
			newList.display();

			break;

		case 2://display front value
			
			currentMenu.clearScreen();
			
			dispFront = newList.getFront();

			if (dispFront)
			{
				cout << "The first item in the queue is ";
				cout << dispFront << ".";
			}
			break;

		case 3://Delete from head (front)

			currentMenu.clearScreen();

			newList.removeFront();
			//newList.display();

			break;

		case 4://Display the queue

			currentMenu.clearScreen();
			newList.display();

			break;

		case 5://Exit

			cout << "Exiting the program\n";
			break;

		default://invalid menu option

			cout << "Invalid menu choice! Please try again\n";
			currentMenu.clearScreen();

		}
	}

	return 0;
}
