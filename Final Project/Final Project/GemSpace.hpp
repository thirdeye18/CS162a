/*********************************************************************
** Program name: Final Project
** Filename: GemSpace.hpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the implementation file for the Gem Space
**				derived Space class.
*********************************************************************/

#ifndef GEM_SPACE_HPP
#define GEM_SPACE_HPP

#include "Space.hpp"

class GemSpace :
	public Space
{
public:
	GemSpace();
	virtual ~GemSpace();

	virtual void explore(int eX, int eY);
	virtual void activate();
};

#endif // !GEM_SPACE_HPP