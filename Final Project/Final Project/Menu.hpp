/*********************************************************************
** Program name: Final Project
** Filename: Menu.hpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the implementation for my menu class.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "InputValidation.hpp"

using std::cin;

using std::vector;
using std::string;
using std::ifstream;
using std::ios;
using std::cout;
using std::endl;

enum MenuOption { MENU1, MENU2, MENU3, MENU4, MENU5, MENU_EXIT };

class Menu
{
private:
	vector <string> options;

public:
	Menu(string fileName);
	void addOption(string fileNameIn);
	void printMenu();
	void clearScreen();
	int userChoice(int options);
};

#endif
