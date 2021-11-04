/*********************************************************************
** Program name: Final Project
** Filename: StandardSpace.hpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the implementation file for the Standard
**				Space derived Space class.
*********************************************************************/

#ifndef STANDARD_SPACE_HPP
#define STANDARD_SPACE_HPP

#include "Space.hpp"

class StandardSpace :
	public Space
{
private:

public:
	StandardSpace();
	virtual ~StandardSpace();

	virtual void explore(int eX, int eY);
	virtual void activate();
};

#endif // !STANDARD_SPACE_HPP