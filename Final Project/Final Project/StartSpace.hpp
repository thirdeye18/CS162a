/*********************************************************************
** Program name: Final Project
** Filename: StartSpace.hpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the implementation file for the Start Space
**				derived from the Space class.
*********************************************************************/

#ifndef START_SPACE_HPP
#define START_SPACE_HPP

#include <iostream>

#include "Space.hpp"

using std::cout;
using std::endl;

class StartSpace :
	public Space
{
private:

public:
	StartSpace();
	virtual ~StartSpace();

	virtual void explore(int eX, int eY);
	virtual void activate();
};

#endif // !START_SPACE_HPP