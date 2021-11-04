
/*********************************************************************
** Program name: Final Project
** Filename: TreasureSpace.hpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the implementation file for the Treasure
**				Space derived Space class.
*********************************************************************/

#ifndef TREASURE_SPACE_HPP
#define TREASURE_SPACE_HPP

#include "Space.hpp"

class TreasureSpace :
	public Space
{
private:

public:
	TreasureSpace();
	virtual ~TreasureSpace();

	virtual void explore(int eX, int eY);
	virtual void activate();
};

#endif // !TREASURE_SPACE_HPP