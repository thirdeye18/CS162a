/*********************************************************************
** Program name: Final Project
** Filename: BoardLayout2.hpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: This is the implementation for the Creature list.
*********************************************************************/

#ifndef BOARD_LAYOUT2_HPP
#define BOARD_LAYOUT2_HPP

#include <iostream>

#include "StartSpace.hpp"
#include "ExitSpace.hpp"
#include "GemSpace.hpp"
#include "StandardSpace.hpp"
#include "TreasureSpace.hpp"


using std::cout;
using std::endl;

class BoardLayout2
{
protected:

	//generating ListNode to hold pointers
	struct ListNode
	{
		Space* spacePtr;
		ListNode* right;
		ListNode* left;
		ListNode* up;
		ListNode* down;

		//Constructor
		ListNode(int type)
		{
			if (type == 1)
			{
				spacePtr = new StartSpace;
			}
			else if (type == 2)
			{
				spacePtr = new StandardSpace;
			}
			else if (type == 3)
			{
				spacePtr = new TreasureSpace;
			}
			else if (type == 4)
			{
				spacePtr = new GemSpace;
			}
			else
			{
				spacePtr = new ExitSpace;
			}
			
			right = nullptr;
			left = nullptr;
			up = nullptr;
			down = nullptr;
		}
	};

	ListNode* center;
	ListNode* temp;

	int spaceCount;
	int totalTiles;
	int gemRooms;

public:
	BoardLayout2();
	~BoardLayout2();
	
	void addStart();
	void addRight();
	void addLeft();
	void addUp();
	void addDown();

	int spacePicker();

	//void display();
	//void reverseDisplay();
};

#endif