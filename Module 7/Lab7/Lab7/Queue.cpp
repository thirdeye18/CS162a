/*********************************************************************
** Program name: Lab 7
** Filename: Queue.cpp
** Author: Justin Hammel
** Date: 5/22/2017
** Description: This contains the function definitions for the queue
**				doubly-linked list lab.  The constructor stores an 
**				integer in the value field of the node and defaults 
**				the next and previous pointers to NULL.  There is a 
**				method to add new nodes to back of the list.  There
**				is also a method to display the contents of the list
**				by traversing forwards through the list.  Last there  
**				is a method to add nodes to the back of the list.
*********************************************************************/

#include "Queue.hpp"

/*Constructor*/

Queue::Queue()
{
	front = NULL;
	back = NULL;
	temp = NULL;
}

/*Destructor, adapted from textbook.*/

Queue::~Queue()
{
	QueueNode* nodePtr = front;
	while (nodePtr != NULL)
	{
		QueueNode* garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage;
	}
}

/*Function adds a value to the end of the list.  Takes the integer
value to be added as a parameter.*/

void Queue::addBack(int val)
{
	if (front == NULL)
	{
		temp = new QueueNode(val);
		front = temp;
		back = temp;
		cout << "new list\n";
	}
	else
	{
		temp = new QueueNode(val);
		back->next = temp;
		temp->prev = back;
		back = temp;
	}
}

/*Function returns the front value in the queue.  If the list is 
empty prints a message and returns 0*/

int Queue::getFront()
{
	if (front == NULL)
	{
		cout << "The list is empty!\n";
		return 0;
	}
	else
	{
		return front->value;
	}
}

/*Deletes a node from the front of the list.  If the list is empty 
displays a message stating the list is empty.*/

void Queue::removeFront()
{
	if (front == NULL)
	{
		cout << "The list is Empty!\n";
	}
	else if (front->next == NULL)
	{
		delete front;
		front = NULL;
	}
	else
	{
		temp = front;
		front = front->next;
		front->prev = NULL;
		delete temp;
	}
}

/*This funtion prints the contents of the list starting at head.*/

void Queue::display()
{
	if (front == NULL)
	{
		cout << "The list is empty!\n";
	}
	else
	{
		cout << "The queue is: ";
		QueueNode* nodePtr = front;
		while (nodePtr != NULL)
		{
			cout << nodePtr->value << " ";
			nodePtr = nodePtr->next;
		}
		cout << endl;
	}
}
