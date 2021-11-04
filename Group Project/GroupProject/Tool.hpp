/*********************************************************************
** Program name: Group Project - Rock Paper Scissors
** Author: Faiz Azhar, Justin Hammel, Katherine Isabella, Hao Liu,
**		   and Philip Reed
** Date: 08 May 2017
** Description: This class creates a virtual tool which has a certain
**				(integer) amount of strength and a type.
**				The type of the tool is unchangeable once the tool is
**				constructed, but the strength of the tool can change
**				using the setStrength(int) function.
*********************************************************************/

#ifndef TOOL_HPP
#define TOOL_HPP

//creates three fight outcomes to be used in derived classes
enum FightOutcome { USER_WON, COMPUTER_WON, DRAW };

class Tool
{

private:

protected:

	int strength;
	char type;

public:

	Tool();
	Tool(int);
    virtual ~Tool();

	virtual FightOutcome fight(Tool*) = 0;

	char getType() const;
	int getStrength() const;

};

#endif
