/*********************************************************************
** Program name: Lab 3
** Filename: IntList.hpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: This is the implementation for the Integer Linked 
**				linked list class.
*********************************************************************/

#ifndef INT_LIST_HPP
#define INT_LIST_HPP

#include <iostream>

using std::cout;
using std::endl;

class IntList
{
protected:

	//generating ListNode to hold integer values
	struct ListNode
	{
		int value;
		ListNode* next;
		ListNode* prev;

		//Constructor
		ListNode(int value1)
		{
			value = value1;
			next = NULL;
			prev = NULL;
		}
	};

	ListNode* head;
	ListNode* tail;
	ListNode* temp;

public:
	IntList();
	~IntList();

	void addEnd(int num);
	void addFront(int num);
	void removeEnd();
	void removeFront();
	void display();
	void reverseDisplay();
};

#endif