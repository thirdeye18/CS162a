/*********************************************************************
** Program name: Project2
** Filename: Item.hpp
** Author: Justin Hammel
** Date: 5/1/2017
** Description: This is the implementation file for my Item class.
*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iomanip>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::setprecision;
using std::fixed;
using std::showpoint;

class Item
{
private:
	string itemName;
	string unit;
	int qty;
	int price;
	int extPrice;

public:
	Item();
	Item(string, string, int, int);
	~Item();

	string getName() const;
	int getExtPrice() const;

	void printItem();
	bool nameSearch(const Item&) const;

	friend bool operator==(const Item& item1, const Item& item2);
};

#endif