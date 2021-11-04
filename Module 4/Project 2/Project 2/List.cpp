/*********************************************************************
** Program name: Project2
** Filename: List.cpp
** Author: Justin Hammel
** Date: 5/1/2017
** Description: The list class has an array of pointers to item 
				objects.  This contains all the methods necessary to 
				add and remove items fromt the list.  When adding 
				items the list will also be searched to verify no 
				duplicate entries are made.  The class also contains 
				a method to print the list contents by calling the 
				item print method from the item class.  There is a
				to increase the size of the array as needed when the 
				maximum array size is reached.
*********************************************************************/

#include "List.hpp"

List::List()
{
	listSize = 4;
	listCount = 0;
	itemList = new Item[listSize];
}

List::~List()
{
	delete [] itemList;
}

size_t List::getListCount()
{
	return listCount;
}

/*This method adds items to the list array.  Prior to adding checks are
  perforemd to ensure the list array has sufficient space and that the 
  item is not already in the list.  If the items exists already then the
  user is promted to discard item, or update list with new information.*/

void List::addItem(const Item& itemIn)
{
	//Increase list size if needed
	if (listCount == listSize)
	{
		increaseSize();
	}
	//search for duplicates
	bool match = false;
	for (size_t i = 0; i < listCount; i++)
	{
		if (itemIn.nameSearch(itemList[i]))
		{
			match = true;
			cout << "Item already exists in list.\n";
			cout << "Do you want to update the item information or\n";
			cout << " discard the new entry?\n";
			cout << "Update = 1, Discard = 2\n";
			string dupeChoice = " ";
			getline(cin, dupeChoice);
			while (!integerValidation(dupeChoice)
				&& !oneTwoValidation(dupeChoice))
			{
				cout << "Please enter a 1 or 2 for choice\n";
				dupeChoice = " ";
				getline(cin, dupeChoice);
			}
			int intChoice = stringToInt(dupeChoice);
			if (intChoice == 1)
			{
				itemList[i] = itemIn;
			}
			else
			{
				cout << "Item discarded\n";
			}
		}
	}
	if (!match)
	{
		itemList[listCount] = itemIn;
		listCount += 1;
	}
}

/*This method searches the item array for an item to be removed.
  It will call the nameSearch method to determine if the item is in the 
  list and then remove the item if found.*/

void List::remItem(string remName)
{
	for (size_t i = 0; i < listCount; i++)
	{
		if (itemList[i].getName() == remName)
		{
			cout << "Removing item\n";
			for (size_t j = i + 1; j < listCount; j++)
			{
				itemList[i] = itemList[j];
			}
			listCount -= 1;
		}
		else
		{
			cout << "Item not found in list\n";
		}
	}
}

/*This function will iterate through the itemList array calling the 
  printItem function from the Item class.  This will print the 
  contents of the list.  The sumList function is called prior to 
  printing the list to generate a total price for printing.*/

void List::printList()
{
	//get list total price for printing
	sumList();
	for (size_t i = 0; i < listCount; i++)
	{
		cout << "Item " << i + 1 << ": \n";
		itemList[i].printItem();
		cout << endl;
	}
	cout << "Total list price: " << total << endl;
}

/*This function will add the extended price for every item in the list*/

void List::sumList()
{
	for (size_t i = 0; i < listCount; i++)
	{
		total += itemList[i].getExtPrice();
	}
}

/*This function increases the size of the dynamic array.  Each time the 
  function is called the size of the array will be doubled.*/

void List::increaseSize()
{
	size_t biggerSize = listSize * 2;
	//create bigger list array
	Item* biggerList = new Item[biggerSize];
	//Moving items into larger list
	for (size_t i = 0; i < listSize; i++)
	{
		biggerList[i] = itemList[i];
	}
	delete [] itemList;
	//assign address of new list to old list
	itemList = biggerList;
	listSize = biggerSize;
}

