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

#include "Rock.hpp"

/*********************************************************************
** Description: Default constructor which makes use of the inherited 
**				Tool constructor for setting the strength to 1
*********************************************************************/
Rock::Rock() : Tool() {

	this->type = 'R';

}


/*********************************************************************
** Description: Constructor which creates a Rock tool as it takes as
**				parameter strength of a tool and uses the Tool 
**				constructor to set this strength. Also sets the type
**				of the tool to 'r' for rock.
*********************************************************************/
Rock::Rock(int strengthIn) : Tool(strengthIn) {

	this->type = 'R';
}


/*********************************************************************
** Description: Takes as a parameter another Tool to fight the Rock. 
**				Against Scissor tools, the Rock's strength is doubled, 
**				and against Paper tools, the Rock's strength is 
**				halved. There is no change to strength when fighting
**				another Rock tool. The Rock's (potentially) altered
**				strength is compared to the opponent tool's strength
**				and the outcome of the "fight" is returned to the user.
*********************************************************************/
FightOutcome Rock::fight(Tool* opponentTool) {

	FightOutcome currentOutcome = DRAW;

	//if the opponent tool type is paper, the strength of the rock
	// is halved and the strengths are compared to find a winner
	if (opponentTool->getType() == 'P') {

		if ((this->strength * .5) < opponentTool->getStrength()) {

			currentOutcome = COMPUTER_WON;
		}
		else if ((this->strength * .5 ) > opponentTool->getStrength()) {

			currentOutcome = USER_WON;
		}

	}

	//if the opponent tool type is scissor, the strength of the rock
	// is doubled and the strengths are compared to find a winner
	else if (opponentTool->getType() == 'S') {

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

