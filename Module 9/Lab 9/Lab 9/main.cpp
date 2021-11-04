/*********************************************************************
** Program name: Lab 9
** Filename: main.cpp
** Author: Justin Hammel
** Date: 6/4/2017
** Description: Main for the implementation of my STL data structure    
**				functions. This will create the menu for running the
**				functions or exiting the program. 
*********************************************************************/

#include <iostream>
#include <ctime>

#include "InputValidation.hpp"
#include "Menu.hpp"
#include "BufferQueue.hpp"
#include "PalindromeStack.hpp"

const int MENU_OPTIONS = 3;

int main()
{
	//seeding rand for dice and randomStart
	srand(time(NULL));

	//generating the main menu
	Menu mainMenu("MainMenuOptions.txt");

	int choice = 0;

	while (choice != MENU_OPTIONS)
	{
		mainMenu.printMenu();
		cout << "Please select an option from the menu.\n";
		choice = mainMenu.userChoice();

		//Creating object pointers for function runs
		BufferQueue* currentBuffer = nullptr;
		PalindromeStack* currentPalindrome = nullptr;
				
		switch (choice)
		{
		case 1://queue buffer test
		{
			mainMenu.clearScreen();
			
			//getting number of rounds from the user
			cout << "Please enter a positive integer for the number\n";
			cout << "of rounds for the buffer simulation to run.\n";
			string userInput = "";
			int rounds = 0;
			do
			{
				getline(cin, userInput);
				if (!posIntegerValidation(userInput))
				{
					cout << "Invalid input! Enter a positive integer value.\n";
				}
			} while (!posIntegerValidation(userInput));
			rounds = stoi(userInput);
			cout << endl;
			
			//getting keep percentage from the user
			cout << "Enter a positive integer between 1 and 100 for\n";
			cout << "percentage of values to store in the buffer.\n";
			userInput = "";
			int percentKeep = 0;
			do
			{
				getline(cin, userInput);
				if (!posIntegerValidation(userInput))
				{
					cout << "Invalid input! Enter a positive integer value.\n";
					cout << "Value should be between 1 and 100.\n";
				}
			} while (!posIntegerValidation(userInput));
			percentKeep = stoi(userInput);
			cout << endl;

			//getting discard percentage from the user
			cout << "Enter a positive integer between 1 and 100 for\n";
			cout << "percentage of values to remove from the buffer.\n";
			userInput = "";
			int percentDiscard = 0;
			do
			{
				getline(cin, userInput);
				if (!posIntegerValidation(userInput))
				{
					cout << "Invalid input! Enter a positive integer value.\n";
					cout << "Value should be between 1 and 100.\n";
				}
			} while (!posIntegerValidation(userInput));
			percentDiscard = stoi(userInput);
			cout << endl;

			currentBuffer = new BufferQueue(rounds, percentKeep, percentDiscard);
			currentBuffer->runBufferSim();
			currentBuffer->printBuffer();
						
			//Freeing memory for future runs
			delete currentBuffer;
			currentBuffer = nullptr;

			break;
		}

		case 2://Palindrome stack
		{
			mainMenu.clearScreen();
			
			//getting string from user
			cout << "Enter string to have palindrome returned for. ";
			cout << "The string cannot be blank.\n";
			string userString = "";
			do
			{
				getline(cin, userString);
				if (!stringValidation(userString))
				{
					cout << "The string cannot be blank\n";
					string nameChoice = "";
				}
			} while (!stringValidation(userString));

			currentPalindrome = new PalindromeStack;

			currentPalindrome->add2Stack(userString);

			currentPalindrome->add2String();

			cout << "The palindrome for " << userString;
			cout << " is ";
			currentPalindrome->printPalindromeString();
			cout << ".\n";

			delete currentPalindrome;
			currentPalindrome = nullptr;

			break;
		}

		case 3://Exit

			cout << "Exiting the program\n";
			break;

		default://invalid menu option

			cout << "Invalid menu choice! Please try again\n";
			mainMenu.clearScreen();

		}

	}

	return 0;
}