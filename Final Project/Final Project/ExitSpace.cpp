/*********************************************************************
** Program name: Final Project
** Filename: ExitSpace.cpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the Exit Space class derived from the Space 
**				class.
**				
**				Space coordinates will be assigned by the
**				Board class for storing them in the map.
*********************************************************************/

#include "ExitSpace.hpp"

/*Constructors*/

ExitSpace::ExitSpace()
{
}

ExitSpace::ExitSpace(Direction in)
{
	fillSpace("exitSpaceLayout.txt");
	spaceName = "Exit Space";
	spaceEntrance(in);
}

/*Destructor*/

ExitSpace::~ExitSpace()
{
}

void ExitSpace::explore(int eX, int eY)
{
	cout << "There are no paths to explore here.\n";
	cout << "This is the exit.\n" << endl;
}

void ExitSpace::activate()
{
}
