/*********************************************************************
** Program name: Group Project - Rock Paper Scissors
** Author: Faiz Azhar, Justin Hammel, Katherine Isabella, Hao Liu,
**		   and Philip Reed
** Date: 08 May 2017
** Description: This class creates a virtual Rock derived from 
**				the Tool class. Thus, the Rock class has a strength
**				and a type. The Rock can be used to fight other Tool
**				classes with varying success (strength against Paper
**				is halved and strength against Scissors is doubled).
*********************************************************************/

#ifndef ROCK_HPP
#define ROCK_HPP

#include "Tool.hpp"

class Rock : public Tool
{

private:


public:

	Rock();
	Rock(int);

	FightOutcome fight(Tool*);

};

#endif

