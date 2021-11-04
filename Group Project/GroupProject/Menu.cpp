/*********************************************************************
 ** Filename: Menu.hpp
 ** Author: Phil Reed
 ** Date: 4-16-2017
 ** Description: Generic functions to build a menu. Credit to Harlan
 James: https://github.com/Gzxgzxgzx/introduction-to-programming/tree/master/menu_example
 *********************************************************************/

#include "Menu.hpp"

/*********************************************************************
 ** Description: Creates a Menu object with title t.
 *********************************************************************/
Menu::Menu(std::string t) {
    title = t;
}

/*********************************************************************
 ** Description: Adds a new Entry with title t and index c.
 *********************************************************************/
void Menu::addMenuItem(std::string t, int c) {
    entries.push_back({c, t});
}

/*********************************************************************
 ** Description: Prints menu to stdout.
 *********************************************************************/
void Menu::printMenu() {
    printf("%s\n", title.c_str());
    // Iterates over Entry array and prints each item
    for (Entry entry : entries) {
        printf("\t%d) %s\n", entry.index, entry.title.c_str());
    }
}

/*********************************************************************
 ** Description: Retrieves user input and returns to caller. Prints
 the menu to stdout.
 *********************************************************************/
int Menu::getItem() {
    if (entries.size() == 0) {
        return 0;
    }
    printMenu();
    int i;
	get_int_input_and_validate(i);
    return i;
}
