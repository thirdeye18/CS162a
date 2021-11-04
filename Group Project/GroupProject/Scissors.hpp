/*********************************************************************
** Program name: Group Project - Rock Paper Scissors
** Author: Faiz Azhar, Justin Hammel, Katherine Isabella, Hao Liu,
**		   and Philip Reed
** Date: 08 May 2017
** Description: This class creates a virtual scissors which is derived 
**				from the Tool class. Thus, the Scissors class has a 
**				strength and a type. The Scissors can be used to 
**				fight other Tool classes with varying success 
**				(strength against Rock is halved and strength against 
**				Paper is doubled). 
*********************************************************************/

#ifndef SCISSORS_HPP
#define SCISSORS_HPP

#include "Tool.hpp"

class Scissors : public Tool
{

private:


public:

	Scissors();
	Scissors(int);

	FightOutcome fight(Tool*);

};

#endif


