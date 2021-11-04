/*********************************************************************
** Program name: Project2
** Filename: Item.cpp
** Author: Justin Hammel
** Date: 5/1/2017
** Description: The item class contains the methods needed to create 
				new items to go in the array created in the List 
				class.  Item names and units will be entered as 
				strings.  Quantity and price have to be enetered as 
				integers.  Input validation verifies that integer 
				input is received.  The printItem method works with 
				the printList function to print the contents of the 
				Item array.  Extended price for each item is 
				calculated at the time of object creation.
*********************************************************************/

#include "Item.hpp"

/*Constructors*/

Item::Item()
{
	itemName = " ";
	unit = " ";
	qty = 0;
	price = 0;
}

Item::Item(string nameIn, string unitIn, int qtyIn, int priceIn)
{
	itemName = nameIn;
	unit = unitIn;
	qty = qtyIn;
	price = priceIn;
	extPrice = price * qty;
}

/*Destructor*/

Item::~Item()
{
}

string Item::getName() const
{
	return itemName;
}

int Item::getExtPrice() const
{
	return extPrice;
}

void Item::printItem()
{
	cout << itemName << endl;
	cout << unit << endl;
	cout << qty << endl;
	cout << setprecision(2) << fixed << showpoint;
	cout << price << endl;
}

/*This method uses the == operator overload to compare the Item calling 
  the function to the one passed to it.  If a match is found returns true.*/

bool Item::nameSearch(const Item& itemTest) const
{
	if (*this == itemTest)
	{
		return true;
	}
	return false;
}

/*This == operator overload compares the names of two items and 
  returns true if a match is found.*/

bool operator==(const Item& item1,const Item& item2)
{
	return item1.getName() == item2.getName();
}

