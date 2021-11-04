/*********************************************************************
** Program name: Project1
** Filename: Menu.hpp
** Author: Justin Hammel
** Date: 4/17/2017
** Description: 
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <cstdlib>

using std::vector;
using std::string;
using std::fstream;
using std::ios;
using std::cout;
using std::endl;

enum MenuOption { MENU1, MENU2, MENU3, MENU4, MENU5, MENU_EXIT };

class Menu
{
private:
	vector <string> options;

public:
	void addOption();
	void printMenu();
	void clearScreen();

	//Functionality not working yet
	//void userChoice(int choice);

};

#endif