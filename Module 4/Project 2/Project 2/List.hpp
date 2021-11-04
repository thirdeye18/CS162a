/*********************************************************************
** Program name: Project2
** Filename: List.hpp
** Author: Justin Hammel
** Date: 5/1/2017
** Description: This is the implementation file for my List class.
*********************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include <string>
#include <iomanip>
#include <iostream>

#include "Item.hpp"
#include "InputValidation.hpp"

using std::string;
using std::setprecision;
using std::fixed;
using std::showpoint;
using std::cin;

class List
{
private:
	size_t listSize;
	size_t listCount;
	Item* itemList;
	int total;

public:
	List();
	~List();

	size_t getListCount();

	void addItem(const Item&);
	void remItem(string);
	void printList();
	void sumList();
	void increaseSize();

};

#endif