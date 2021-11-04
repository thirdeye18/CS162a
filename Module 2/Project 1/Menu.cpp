/*********************************************************************
** Program name: Project1
** Filename: Menu.cpp
** Author: Justin Hammel
** Date: 4/17/2017
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

void Menu::addOption()
{
	//setup objects to read text file
	string addMenuOptions;
	fstream menuFile;
	
	//open text file
	menuFile.open ("MenuOptions.txt", ios::in);

	//Verify file exists
	if (!menuFile)
	{
		cout << "Unable to find MenuOptions.txt\n";
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
	cout << "Enter number coresponding to menu choice\n";
}

/*This function clears the screen and moves the cursor to the upper
left corner of the screen*/

void Menu::clearScreen()
{
	std::cout << "\033[2J\033[1;1H";
}

/*I was working on getting user choices to correspond to the enum
  values created.  Functionality is not working at this time*/

//void Menu::userChoice(int choice)
//{
//	/*while (choice != MENU_EXIT)
//	{
//		switch (choice)
//		{
//		case MENU1:
//		case MENU2:
//		case MENU3:
//		case MENU4:
//		case MENU5:
//		case MENU_EXIT:
//		}
//	}*/
//}


