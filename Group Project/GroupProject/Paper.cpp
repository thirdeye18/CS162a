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

#include "Paper.hpp"
#include <stdio.h>

/*********************************************************************
** Description: Default constructor which makes use of the inherited 
**				Tool constructor for setting the strength to 1
*********************************************************************/
Paper::Paper() : Tool() {

	this->type = 'P';
}


/*********************************************************************
** Description: Constructor which creates a Paper tool as it takes as
**				parameter strength of a tool and uses the Tool 
**				constructor to set this strength. Also sets the type
**				 of the tool to 'p' for paper.
*********************************************************************/
Paper::Paper(int strengthIn) : Tool(strengthIn) {

	this->type = 'P';
}


/*********************************************************************
** Description: Takes as a parameter another Tool to fight the Paper.
**				Against Rock tools, the Paper's strength is doubled,
**				and against Scissors tools, the Paper's strength is
**				halved. There is no change to strength when fighting
**				another Paper tool. The Paper's (potentially) altered
**				strength is compared to the opponent tool's strength
**				and the outcome of the "fight" is returned to the user
*********************************************************************/
FightOutcome Paper::fight(Tool* opponentTool) {

	FightOutcome currentOutcome = DRAW;

	//if the opponent tool type is scissor, the strength of the paper
	// is halved and the strengths are compared to find a winner
	if (opponentTool->getType() == 'S') {

		if ((this->strength * .5) < opponentTool->getStrength()) {

			currentOutcome = COMPUTER_WON;
		}
		else if ((this->strength * .5) > opponentTool->getStrength()) {

			currentOutcome = USER_WON;
		}

	}

	//if the opponent tool type is rock, the strength of the paper
	// is doubled and the strengths are compared to find a winner
	else if (opponentTool->getType() == 'R') {

		if ((this->strength * 2) < opponentTool->getStrength()) {

			currentOutcome = COMPUTER_WON;
		}
		else if ((this->strength * 2) > opponentTool->getStrength()) {

			currentOutcome = USER_WON;
		}
	}

	//if the tool types are the same, then the strengths
	//are simply compared to find a winner
	else {

		if (this->strength < opponentTool->getStrength()) {
            
			currentOutcome = COMPUTER_WON;
		}
		else if (this->strength > opponentTool->getStrength()) {
            
            currentOutcome = USER_WON;
		}
	}

	return currentOutcome;
}

