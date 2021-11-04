/*********************************************************************
** Program name: Final Project
** Filename: StartSpace.cpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the Start Space derived class for my Final 
**				Project. This space only has left and right paths
**				by default.  There will only be one of this space per
**				game.  There are no gems in this space.  The palyer 
**				starts the game in this space.
*********************************************************************/

#include "StartSpace.hpp"

/*constructors*/

StartSpace::StartSpace() : Space()
{
	fillSpace("startSpaceLayout.txt");
	spaceName = "Start Space";
}

/*Destructor*/

StartSpace::~StartSpace()
{
}

/*Generates two branching paths on the left and right leaving the 
up and down pointers set to nullptr.*/

void StartSpace::explore(int eX, int eY)
{
	cout << "There are no paths to explore here.\n";
	cout << "Move to another space.\n" << endl;
}

/*Start Space has nothing to activate, so message displayed.*/

void StartSpace::activate()
{
	cout << "There is nothing to activate here.\n";
	cout << "Move to another space.\n" << endl;
}