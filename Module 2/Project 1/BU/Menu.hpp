/*********************************************************************
** Program name: Project1
** Filename: menu.hpp
** Author: Justin Hammel
** Date: 4/15/2017
** Description: Implementation of the menu class.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

enum Options { MENU1, MENU2, MENU3, MENU4, MENU5, MENU_EXIT };

class Menu
{

private:


	
public:
	Menu ();
	void addOption(option);
	void useMenu (choice);
	void printMenu();
	
};

#endif