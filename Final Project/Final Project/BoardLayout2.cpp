/*********************************************************************
** Program name: Final Project 
** Filename: BoardLayout2.cpp
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

#include "BoardLayout2.hpp"

/*Constructor*/

BoardLayout2::BoardLayout2()
{
	center = nullptr;
	temp = nullptr;

	spaceCount = 0;
	totalTiles = 19;
	gemRooms = 4;

	addStart();
	addRight();
	addLeft();
}

/*Destructor, adapted from textbook.*/

BoardLayout2::~BoardLayout2()
{
	ListNode* nodePtr = center;
	while (nodePtr != nullptr)
	{
		ListNode* garbage = nodePtr;
		nodePtr = nodePtr->left;
		delete garbage->spacePtr;
		delete garbage;
	}
}

/*Function adds a value to the center of the board.  This will be the
start space.Space* spaceIn*/

void BoardLayout2::addStart()
{
	if (center == nullptr)
	{
		temp = new ListNode(1);
		center = temp;
		spaceCount += 1;
		totalTiles -= 1;
	}
}

void BoardLayout2::addRight()
{
}

void BoardLayout2::addLeft()
{
}

void BoardLayout2::addUp()
{
}

void BoardLayout2::addDown()
{
}

/*Randomly determines what type of space will be made. Int returned
corresponds to the type of space that will be made. 1 is the exit,
2-5 are the gem rooms (only 4 total), all other rolls yield plain
room.  Plain room has 50% chance of containing treasure. Exit room
is not available unitl 5 spaces have been generated, controlled by
the spaceCount variable. The tileCount variable decreases the max
random value (as spaces created tiles available decrease by 1).*/

int BoardLayout2::spacePicker()
{
	int randNum = 0;

	randNum = rand() % totalTiles + 1;

	if (spaceCount < 5)
	{
		//2-5 creating gem room
		if ((randNum >= 2 || randNum <= 5) && gemRooms > 0)
		{
			gemRooms -= 1;	//adjust available number of gem rooms
			return 4;
		}
		//Standard room in all other cases
		else
		{
			//50% chance to have treasure room
			randNum = rand() % 2;
			if (randNum)
			{
				return 2;
			}
			else
			{
				return 3;
			}
		}
	}
	else
	{
		//1 generates exit room
		if (randNum == 1)
		{
			return 5;
		}
		//2-5 creating gem room
		else if ((randNum >= 2 || randNum <= 5) && gemRooms > 0)
		{
			gemRooms -= 1;	//adjust available number of gem rooms
			return 4;
		}
		//Standard room in all other cases
		else
		{
			//50% chance to have treasure room
			randNum = rand() % 2;
			if (randNum)
			{
				return 2;
			}
			else
			{
				return 3;
			}
		}
	}
}

/*Function adds a value to the head of the list.  Takes the creature
pointer to be added as a parameter.*/

//void BoardLayout2::addFront(Space* spaceIn)
//{
//	if (head == nullptr)
//	{
//		temp = new ListNode(creatIn);
//		head = temp;
//		tail = temp;
//	}
//	else
//	{
//		temp = new ListNode(creatIn);
//		temp->next = head;
//		head->prev = temp;
//		head = temp;
//	}
//
//}

/*Deletes node from the end of the list. This method is not used in
the Tournament.*/

//void BoardLayout2::removeEnd()
//{
//	if (head == nullptr)
//	{
//		cout << "The list is Empty!\n";
//	}
//	else if (head->next == nullptr)
//	{
//		delete head;
//		head = nullptr;
//	}
//	else
//	{
//		temp = tail;
//		tail = tail->prev;
//		tail->next = nullptr;
//		delete temp;
//	}
//}

/*This funtion prints the contents of the list starting at head.*/

//void BoardLayout2::display()
//{
//	if (head == nullptr)
//	{
//		cout << "The list is empty!\n";
//	}
//	else
//	{
//		ListNode* nodePtr = head;
//		while (nodePtr != nullptr)
//		{
//			nodePtr->creaturePtr->printName();
//			cout << " the ";
//			nodePtr->creaturePtr->printType();
//			cout << endl;
//			nodePtr = nodePtr->next;
//		}
//		cout << endl;
//	}
//}

/*This funtion prints the contents of the list starting at tail. Is
not used for the Tournament.*/

//void BoardLayout2::reverseDisplay()
//{
//	cout << "The list in reverse is: ";
//	ListNode* nodePtr = tail;
//	if (head == nullptr)
//	{
//		cout << "The list is empty\n" << endl;
//	}
//	while (nodePtr != nullptr)
//	{
//		nodePtr->creaturePtr->printName();
//		cout << endl;
//		nodePtr = nodePtr->prev;
//	}
//	
//}
