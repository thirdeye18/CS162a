/*********************************************************************
** Program name: Project2
** Filename: main.cpp
** Author: Justin Hammel
** Date: 5/1/2017
** Description: This is my main for running and testing my List
**				program.
********************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

#include "Menu.hpp"
#include "InputValidation.hpp"
#include "List.hpp"

using std::cout;
using std::string;
using std::setprecision;
using std::fixed;
using std::showpoint;

int main()
{
	/*I was trying to test my float conversion and gave up
	  the code works to validate a float input, but cannot 
	  get stof, atof, or strtof working.  All methods return 
	  value with the decimal portion truncated.
	string test = " ";
	float testFloat = 0.0;
	getline(cin, test);
	if (floatValidation(test))
	{
		cout << "The number is a float\n";
	}
	if (!floatValidation(test))
	{
		cout << "Failed float test\n";
	}
	cout << setprecision(2) << fixed << showpoint;
	cout << test << endl;
	cout << stringToFloat(test) << endl;*/

	Menu currentMenu;

	int choice = 0;
	size_t itemCounter, mainListSize;
	itemCounter = 0;
	mainListSize = 4;
	List* currentList = NULL;
	bool listCreated = false;

	while (choice != 5)
	{
		cout << endl;
		currentMenu.printMenu();
		choice = currentMenu.userChoice();
		
		//Prevent adding of removing items if list not created

		//Create list
		if (choice == 1)
		{
			currentMenu.clearScreen();
			cout << "Creating list.  List will start with a capacity of 4 and ";
			cout << "grow as needed.\n";
			currentList = new List;
			listCreated = true;
		}
		
		//Add items
		else if (choice == 2)
		{
			if (listCreated)
			{
				string aName = " ";
				string aUnit = " ";
				string aQty = " ";
				string aPrice = " ";
				currentMenu.clearScreen();

				cout << "Please enter the item name.\n";
				getline(cin, aName);
				while (aName == " ")
				{
					cout << "Blank input not allowed.\n";
					cout << "Please enter a valid item name.\n";
					getline(cin, aName);
				}

				cout << "Please enter the item unit.\n";
				getline(cin, aUnit);
				while (aName == " ")
				{
					cout << "Blank input not allowed.\n";
					cout << "Please enter a valid item unit.\n";
					getline(cin, aUnit);
				}

				cout << "Please enter an integer value for quantity.\n";
				getline(cin, aQty);
				while (!integerValidation(aQty))
				{
					cout << "Please enter an integer value for quantity.\n";
					aQty = " ";
					getline(cin, aQty);
				}
				int conQty = stringToInt(aQty);

				cout << "Please enter an integer value for item unit price\n";
				cin >> aPrice;
				while (!integerValidation(aPrice))
				{
					cout << "Please enter an integer value for unit price.\n";
					aPrice = " ";
					getline(cin, aPrice);
				}
				int conPrice = stringToInt(aPrice);

				//Creating new item
				Item* iPtr = new Item(aName, aUnit, conQty, conPrice);

				//Passing item to the list
				currentList->addItem(*iPtr);

				delete iPtr;
				iPtr = NULL;
			}
			else
			{
				cout << "List not created yet.\n";
				cout << "Create list first with option 1\n";
			}
		}
		
		//Remove items
		else if (choice == 3)
		{
			currentMenu.clearScreen();

			string searchName = " ";
			if (listCreated && currentList->getListCount() > 0)
			{
				cout << "Enter the name of the item to be removed.\n";
				getline(cin, searchName);
				while (searchName == " ")
				{
					cout << "Blank input not allowed\n";
					cout << "Please enter a valid name to search for\n";
					getline(cin, searchName);
				}
				currentList->remItem(searchName);
			}
			else
			{
				cout << "List not created yet.\n";
				cout << "Create list first with option 1 \n";
				cout << "then add items to the list prior \n";
				cout << "to trying to remove items\n";
			}
		}
		
		//Display list
		else if (choice == 4)
		{
			if (listCreated)
			{
				currentMenu.clearScreen();
				currentList->printList();
			}
			else
			{
				cout << "List not created yet.\n";
				cout << "Create list first with option 1\n";
			}
		}
		
		//Exit program
		else if (choice == 5)
		{
			cout << "Exiting the program\n";

			//cleaning up pointers
			delete currentList;
			currentList = NULL;
		}
		else
		{
			currentMenu.clearScreen();
			cout << "Invalid menu choice! Please try again\n";
		}
	}

	return 0;
}