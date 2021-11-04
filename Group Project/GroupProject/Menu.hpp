/*********************************************************************
 ** Filename: Menu.hpp
 ** Author: Phil Reed
 ** Date: 4-16-2017
 ** Description: Generic functions to build a menu. Credit to Harlan
 James: https://github.com/Gzxgzxgzx/introduction-to-programming/tree/master/menu_example
 *********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#define MENU_ENTRIES 10

#include <stdio.h>
#include <iostream>
#include "InputValidation.hpp"
#include <vector>

class Menu {
private:
    // Holds index and title information for each menu entry
    struct Entry {
        int index;
        std::string title;
    };
    std::string title;
    std::vector<Entry> entries;
public:
    Menu(std::string t);
    void printMenu(); // Print menu to stdout
    void addMenuItem(std::string t, int c); // Add menu entry
    int getItem(); // Get user input
};

#endif /* MENU_HPP */
