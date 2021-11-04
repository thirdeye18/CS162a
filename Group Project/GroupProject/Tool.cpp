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

#include "Tool.hpp"

/*********************************************************************
** Description: Default constructor which creates a tool with the
**				strength of 1
*********************************************************************/
Tool::Tool() {

	this->strength = 1;
}


/*********************************************************************
** Description: Constructor which creates a tool by taking as
**				parameters the strength of the tool tool
*********************************************************************/
Tool::Tool(int toolStrength) {

	this->strength = toolStrength;
	
}

Tool::~Tool() {
    
}

/*********************************************************************
** Description: Allows access to the type of the tool
**
*********************************************************************/
char Tool::getType() const {

	return this->type;
}


/*********************************************************************
** Description: Allows access to the strength of the tool
**
*********************************************************************/
int Tool::getStrength() const {

	return this->strength;
}


