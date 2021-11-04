/*********************************************************************
** Program name: Project 4
** Filename: CreatureList.hpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: This is the implementation for the Creature list.
*********************************************************************/

#ifndef CREATURE_LIST_HPP
#define CREATURE_LIST_HPP

#include <iostream>

#include "Creature.hpp"

using std::cout;
using std::endl;

class CreatureList
{
protected:

	//generating ListNode to hold pointers
	struct ListNode
	{
		Creature* creaturePtr;
		ListNode* next;
		ListNode* prev;

		//Constructor
		ListNode(Creature* creat1)
		{
			creaturePtr = creat1;
			next = nullptr;
			prev = nullptr;
		}
	};

	ListNode* head;
	ListNode* tail;
	ListNode* temp;

public:
	CreatureList();
	~CreatureList();

	Creature* removeFront();
	
	void addEnd(Creature* creatIn);
	void addFront(Creature* creatIn);

	//removeEnd() not used for Project 4
	void removeEnd();

	void display();
	void reverseDisplay();
};

#endif