/*********************************************************************
** Program name: Final Project
** Filename: Menu.cpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is my simple menu class.  It contains methods to 
**				add desired options to the menu, print the menu to 
**				the screen, clear the screen, and accept a menu choice
**				fromt the user returning an integer value based on
**				the choice.
*********************************************************************/

#include "Menu.hpp"

/*This function reads the available menu options from 
  MenuOptions.txt and places them into the Menu object vector.  
  Menu options are placed into te text file seperated by a 
  \n character. Method was adapted partially from 
  Gaddis, Walters, and Muganda Text Pg. 867, 868*/


Menu::Menu(string fileName)
{
	this->addOption(fileName);
}

/*This adds options to the menu from text file name supplied as
a parameter to the function.  Menu options are stored in a text
file with different options preceded by an integer.  Seperate 
options are each on their own line.*/

void Menu::addOption(string fileNameIn)
{
	//setup objects to read text file
	string addMenuOptions;
	ifstream menuFile;
	
	//open text file
	menuFile.open (fileNameIn, ios::in);

	//Verify file exists
	if (!menuFile)
	{
		cout << "Unable to find " << fileNameIn << " \n";
	}
	
	//start reading with first line of file
	getline(menuFile, addMenuOptions);
	while (menuFile)
	{
		//while successful push string to vector
		//then read next line
		options.push_back(addMenuOptions);
		getline(menuFile, addMenuOptions);
	}

	//close text file
	menuFile.close();
}

/*This function prints the menu to the screen by outputing the 
  contents the options vector. The options vector contains all 
  the menu commands*/

void Menu::printMenu()
{
	for (size_t i = 0; i < options.size(); i++)
	{
		cout << options.at(i) << endl;
	}
}

/*This function clears the screen and moves the cursor to the upper
left corner of the screen or on windows system uses system()*/

void Menu::clearScreen()
{
#if defined(_WIN32)
	//clear comand if windows detected
	system("cls");
#else
	//clear using ascii for others
	std::cout << "\033[2J\033[1;1H";
#endif 
}

/*This function receives string input from the user. Integer input 
  validation is performed. If positive integer input is received the 
  function verifies the range is acceptable based on the int value 
  that was passed to the userChoice function. The int options passed
  to the function is the high range of the available options. If all 
  validations pass int value is returned.*/

int Menu::userChoice(int options)
{
	string stringChoice = " ";
	int chosenInt = 0;

	getline(cin, stringChoice);

	do
	{
		while (!posIntegerValidation(stringChoice))
		{
			cout << "Invalid choice\n";
			cout << "Please enter valid integer corresponding";
			cout << " to the available options\n";
			stringChoice = " ";
			getline(cin, stringChoice);
		}
	
		//converting to int for return and further verification
		chosenInt = stoi(stringChoice);
		if (!rangeValidation(chosenInt, 1, options))
		{
			cout << "Invalid choice\n";
			cout << "Please enter valid integer corresponding";
			cout << " to the available options\n";
			stringChoice = " ";
			getline(cin, stringChoice);
			chosenInt = 0;
		}
	}while (chosenInt == 0);

	return chosenInt;
}