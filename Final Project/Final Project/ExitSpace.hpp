/*********************************************************************
** Program name: Final Project
** Filename: ExitSpace.hpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the implementation file for the derived
**				Exit Space class.
*********************************************************************/

#ifndef EXIT_SPACE_HPP
#define EXIT_SPACE_HPP

#include "Space.hpp"

class ExitSpace :
	public Space
{
public:
	ExitSpace();
	ExitSpace(Direction in);
	virtual ~ExitSpace();

	virtual void explore(int eX, int eY);
	virtual void activate();
};

#endif