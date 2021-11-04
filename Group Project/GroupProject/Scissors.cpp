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


#include "Scissors.hpp"

/*********************************************************************
** Description: Default constructor which makes use of the inherited 
**				Tool constructor for setting the strength to 1
*********************************************************************/
Scissors::Scissors() : Tool() {

	this->type = 'S';
}


/*********************************************************************
** Description: Constructor which creates a Scissor tool as it takes 
**				as parameter strength of a tool and uses the Tool 
**				constructor to set this strength. Also sets the type 
**				of the tool to 's' for scissors.
*********************************************************************/
Scissors::Scissors(int strengthIn) : Tool(strengthIn) {
	
	this->type = 'S';
}


/*********************************************************************
** Description: Takes as a parameter another Tool to fight the
**				Scissors. Against Rock tools, the Scissors strength
**				is halved. Against Paper tools the Scissors strength
**				is doubled. There is no strength change when fighting
**				another Scissor tool. The Scissor (potentially) altered
**				strength is compared to the opponent tool's strength
**				and the outcome of the "fight" is returned to the user.
*********************************************************************/
FightOutcome Scissors::fight(Tool* opponentTool) {

	FightOutcome currentOutcome = DRAW;

	//if the opponent tool type is rock, the strength of the
	//Scissor is halved and the strengths are compared to find a winner
	if (opponentTool->getType() == 'R') {

		if ((this->strength * .5) < opponentTool->getStrength()) {
			
			currentOutcome = COMPUTER_WON;
		}
		else if ((this->strength * .5) > opponentTool->getStrength()) {
			
			currentOutcome = USER_WON;
		}

	}

	//if the opponent tool type is paper, the strength of the scissors
	// is doubled and the strengths are compared to find a winner
	else if (opponentTool->getType() == 'P') {
		
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

		if (this->strength < opponentTool->getStrength()){

			currentOutcome = COMPUTER_WON;
		}
		else if (this->strength > opponentTool->getStrength()) {

			currentOutcome = USER_WON;
		}
	}

	return currentOutcome;
}
