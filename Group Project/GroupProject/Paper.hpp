/*********************************************************************
** Program name: Group Project - Rock Paper Scissors
** Author: Faiz Azhar, Justin Hammel, Katherine Isabella, Hao Liu,
**		   and Philip Reed
** Date: 08 May 2017
** Description: This class creates a virtual Paper derived from
**				the Tool class. Thus, the Paper class has a strength
**				and a type. The Paper can be used to fight other Tool
**				classes with varying success(strength against Scissors
**				is halved and strength against Rock is doubled).
*********************************************************************/

#ifndef PAPER_HPP
#define PAPER_HPP

#include "Tool.hpp"

class Paper : public Tool
{

private:


public:

	Paper();
	Paper(int);

	FightOutcome fight(Tool*);

};

#endif


