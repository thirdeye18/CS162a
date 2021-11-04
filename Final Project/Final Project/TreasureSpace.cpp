/*********************************************************************
** Program name: Final Project
** Filename: TreasureSpace.cpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the Treasure Space derived class for my Final
**				Project. 
**				
**				There are no gems in this space.  
**				
*********************************************************************/

#include "TreasureSpace.hpp"

/*constructors*/

TreasureSpace::TreasureSpace() : Space()
{
	fillSpace("standardSpaceLayout.txt");
	spaceName = "Treasure Room";
}

/*Destructor*/

TreasureSpace::~TreasureSpace()
{
}

/*Used to add new spaces to the board. Currently being used to 
fill the board randomly for program requirements.*/

void TreasureSpace::explore(int eX, int eY)
{
	int randPath = 0;

	while (randPath == 0)
	{
		randPath = rand() % 4 + 1;
		if (randPath == UP && this->exits[UP] == nullptr)
		{
			//generateSpace(layout, UP);
		}
		else if (randPath == DOWN && this->exits[DOWN] == nullptr)
		{
			//generateSpace(layout, DOWN);
		}
		else if (randPath == LEFT && this->exits[LEFT] == nullptr)
		{
			//generateSpace(layout, LEFT);
		}
		else if (randPath == RIGHT && this->exits[RIGHT] == nullptr)
		{
			//generateSpace(layout, RIGHT);
		}
		else
		{
			randPath = 0;
		}
	}
}

/*Start Space has nothing to activate, so message displayed.*/

void TreasureSpace::activate()
{
	cout << "There is nothing to activate here.\n";
	cout << "Move to another space.\n" << endl;
}