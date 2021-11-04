/*********************************************************************
** Program name: Lab5
** Filename: main.cpp
** Author: Justin Hammel
** Date: 5/8/2017
** Description: Main for the implementation of three recursion 
**				functions.  This will create the menu to allow the 
**				reverseString, sumArray, and triNum functions.  All 
**				inputs for those functions will be gathered from 
**				main.cpp and passed into the functions.
*********************************************************************/

#include <iostream>
#include <string>

#include "recursiveHeader.hpp"
#include "InputValidation.hpp"
#include "Menu.hpp"

int main()
{
	Menu currentMenu;

	int choice = 0;

	while (choice != 4)
	{
		cout << endl;
		currentMenu.printMenu();
		choice = currentMenu.userChoice();

		//Use reverseString
		if (choice == 1)
		{
			currentMenu.clearScreen();

			//get user string input for function
			string userString = "";
			while (!stringValidation(userString))
			{
				cout << "Please enter a string you would like reversed.\n";
				cout << "The string cannot be blank.\n";
				getline(cin, userString);
				if (!stringValidation(userString))
				{
					cout << "Error\n";
					userString = "";
				}
			}


			//output the result of the function call
			cout << "Your original string was: \n";
			cout << userString << endl;
			cout << "The string reversed is ";
			reverseString(userString);
		}

		//Use sumArray, works
		else if (choice == 2)
		{
			currentMenu.clearScreen();

			int* ary;
			size_t size = 0;
			string sizStr = "",
				valStr = "";
			int inputVals = 0;

			//get user input for array size
			while (!posIntegerValidation(sizStr))
			{
				cout << "Enter the size of the array.\n";
				cout << "Input must be a positive integer value.\n";
				getline(cin, sizStr);
				if (!posIntegerValidation(sizStr))
				{
					cout << "Error" << endl;
					sizStr = "";
				}
			}
			size = stringToInt(sizStr);

			//allocate new array
			ary = new int[size];

			//Fill array with values
			for (size_t i = 0; i < size; i++)
			{
				while (!integerValidation(valStr))
				{
					cout << "Enter value to add to array.\n";
					cout << "Input can be a positive or negative integer.\n";
					getline(cin, valStr);
					if (!integerValidation(valStr))
					{
						cout << "Error" << endl;
						sizStr = "";
					}
				}
				ary[i] = stringToInt(valStr);
				valStr = "";
			}

			//output results of function to the screen
			cout << "The sum of the integers in the array is ";
			cout << sumArray(ary, size);

			delete[] ary;
		}

		//use triNumber, works
		else if (choice == 3)
		{
			currentMenu.clearScreen();

			string stringInt = "";
			int funInt = 0;

			//get and validate user input
			while (!integerValidation(stringInt))
			{
				cout << "Please enter integer value you would like to find";
				cout << " the triangular number for.\n";
				getline(cin, stringInt);
				if (!integerValidation(stringInt))
				{
					cout << "Error\n";
					stringInt = "";
					getline(cin, stringInt);
				}
			}
			funInt = stringToInt(stringInt);

			//output the results of the function call
			cout << "The triangular number for " << funInt << " is " << triNum(funInt);
		}

		//Exit program
		else if (choice == 4)
		{
			cout << "Exiting the program\n";
		}

		//invalid menu option
		else
		{
			cout << "Invalid menu choice! Please try again\n";
		}
	}

	return 0;
}
