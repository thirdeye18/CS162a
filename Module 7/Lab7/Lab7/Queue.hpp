/*********************************************************************
** Program name: Lab 7
** Filename: Queue.hpp
** Author: Justin Hammel
** Date: 5/22/2017
** Description: This is the implementation for the Queue 
**				linked list class.
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

using std::cout;
using std::endl;

class Queue
{
protected:

	//generating ListNode to hold integer values
	struct QueueNode
	{
		int value;
		QueueNode* next;
		QueueNode* prev;

		//Constructor
		QueueNode(int value1)
		{
			value = value1;
			next = NULL;
			prev = NULL;
		}
	};

	QueueNode *front;
	QueueNode *back;
	QueueNode* temp;

public:
	Queue();
	~Queue();

	void addBack(int val);
	int getFront();
	void removeFront();
	void display();
};

#endif