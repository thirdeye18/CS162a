/*********************************************************************
** Program name: Lab 6
** Filename: IntList.cpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: This contains the function definitions for my linked 
**				list lab.  The constructor stores an integer in the 
**				value field of the node and defaults the next and 
**				previous pointers to NULL.  There are methods to add
**				new nodes to the head and tail of the list.  There are
**				are also methods to display the contents of the list
**				by traversing both forward and backwards throught the 
**				the list.  Fianlly there are two methods to add and 
**				remove nodes from the head and tail of the list.
*********************************************************************/

#include "IntList.hpp"

/*Constructor*/

IntList::IntList()
{
	head = NULL;
	tail = NULL;
	temp = NULL;
}

/*Destructor, adapted from textbook.*/

IntList::~IntList()
{
	ListNode* nodePtr = head;
	while (nodePtr != NULL)
	{
		ListNode* garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage;
	}
}

/*Function adds a value to the end of the list.  Takes the integer
value to be added as a parameter.*/

void IntList::addEnd(int num)
{
	if (head == NULL)
	{
		temp = new ListNode(num);
		head = temp;
		tail = temp;
		cout << "new list\n";
	}
	else
	{
		temp = new ListNode(num);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}

/*Function adds a value to the head of the list.  Takes the integer
value to be added as a parameter.*/

void IntList::addFront(int num)
{
	if (head == NULL)
	{
		temp = new ListNode(num); 
		head = temp;
		tail = temp;
		cout << "new list\n";
	}
	else
	{
		temp = new ListNode(num);
		temp->next = head;
		head->prev = temp;
		head = temp;
	}

}

/*Deletes node from the end of the list*/

void IntList::removeEnd()
{
	if (head == NULL)
	{
		cout << "The list is Empty!\n";
	}
	else if (head->next == NULL)
	{
		delete head;
		head = NULL;
	}
	else
	{
		temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete temp;
	}
}

/*Deletes a node from the front of the list*/

void IntList::removeFront()
{
	if (head == NULL)
	{
		cout << "The list is Empty!\n";
	}
	else if (head->next == NULL)
	{
		delete head;
		head = NULL;
	}
	else
	{
		temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
	}
}

/*This funtion prints the contents of the list starting at head.*/

void IntList::display()
{
	if (head == NULL)
	{
		cout << "The list is empty!\n";
	}
	else
	{
		cout << "Your linked list is: ";
		ListNode* nodePtr = head;
		while (nodePtr != NULL)
		{
			cout << nodePtr->value << " ";
			nodePtr = nodePtr->next;
		}
		cout << endl;
	}
}

/*This funtion prints the contents of the list starting at tail.*/

void IntList::reverseDisplay()
{
	cout << "The list in reverse is: ";
	ListNode* nodePtr = tail;
	if (head == NULL);
	{
		cout << "The list is empty\n" << endl;
	}
	while (nodePtr != NULL)
	{
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->prev;
	}
	
}
