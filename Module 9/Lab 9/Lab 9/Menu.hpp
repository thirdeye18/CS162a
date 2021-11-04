/*********************************************************************
** Program name: Lab 9
** Filename: Menu.hpp
** Author: Justin Hammel
** Date: 6/4/2017
** Description: 
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include <iostream>
//#include <ostream>
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
	int userChoice();
};

#endif
