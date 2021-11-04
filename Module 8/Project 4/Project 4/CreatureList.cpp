/*********************************************************************
** Program name: Project 4
** Filename: CreatureList.cpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: This contains the function definitions for my linked 
**				list lab.  The constructor stores an integer in the 
**				value field of the node and defaults the next and 
**				previous pointers to nullptr.  There are methods to add
**				new nodes to the head and tail of the list.  There are
**				are also methods to display the contents of the list
**				by traversing both forward and backwards throught the 
**				the list.  Fianlly there are two methods to add and 
**				remove nodes from the head and tail of the list.
*********************************************************************/

#include "CreatureList.hpp"

/*Constructor*/

CreatureList::CreatureList()
{
	head = nullptr;
	tail = nullptr;
	temp = nullptr;
}

/*Destructor, adapted from textbook.*/

CreatureList::~CreatureList()
{
	ListNode* nodePtr = head;
	while (nodePtr != nullptr)
	{
		ListNode* garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage->creaturePtr;
		delete garbage;
	}
}

/*Returns the pointer from the front of the list and assigns new list
head. If the list is empty returns a nullptr. If the item is the last
in the list head is set to nullptr.*/

Creature* CreatureList::removeFront()
{
	Creature* rtnPtr = nullptr;
	if (head == nullptr)
	{
		return nullptr;
	}
	else if (head->next == nullptr)
	{
		rtnPtr = head->creaturePtr;
		//delete head;
		head = nullptr;
		return rtnPtr;
	}
	else
	{
		rtnPtr = head->creaturePtr;
		temp = head;
		head = head->next;
		head->prev = nullptr;
		//delete temp;
		return rtnPtr;
	}
}

/*Function adds a value to the end of the list.  Takes the creature
pointer to be added as a parameter.*/

void CreatureList::addEnd(Creature* creatIn)
{
	if (head == nullptr)
	{
		temp = new ListNode(creatIn);
		head = temp;
		tail = temp;
	}
	else
	{
		temp = new ListNode(creatIn);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}

/*Function adds a value to the head of the list.  Takes the creature
pointer to be added as a parameter.*/

void CreatureList::addFront(Creature* creatIn)
{
	if (head == nullptr)
	{
		temp = new ListNode(creatIn);
		head = temp;
		tail = temp;
	}
	else
	{
		temp = new ListNode(creatIn);
		temp->next = head;
		head->prev = temp;
		head = temp;
	}

}

/*Deletes node from the end of the list. This method is not used in
the Tournament.*/

void CreatureList::removeEnd()
{
	if (head == nullptr)
	{
		cout << "The list is Empty!\n";
	}
	else if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete temp;
	}
}

/*This funtion prints the contents of the list starting at head.*/

void CreatureList::display()
{
	if (head == nullptr)
	{
		cout << "The list is empty!\n";
	}
	else
	{
		ListNode* nodePtr = head;
		while (nodePtr != nullptr)
		{
			nodePtr->creaturePtr->printName();
			cout << " the ";
			nodePtr->creaturePtr->printType();
			cout << endl;
			nodePtr = nodePtr->next;
		}
		cout << endl;
	}
}

/*This funtion prints the contents of the list starting at tail. Is
not used for the Tournament.*/

void CreatureList::reverseDisplay()
{
	cout << "The list in reverse is: ";
	ListNode* nodePtr = tail;
	if (head == nullptr)
	{
		cout << "The list is empty\n" << endl;
	}
	while (nodePtr != nullptr)
	{
		nodePtr->creaturePtr->printName();
		cout << endl;
		nodePtr = nodePtr->prev;
	}
	
}
