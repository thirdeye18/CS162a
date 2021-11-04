/*********************************************************************
** Program name: Group Project - Rock Paper Scissors
** Author: Faiz Azhar, Justin Hammel, Katherine Isabella, Hao Liu, and Philip Reed
** Date: 08 May 2017
** Description: This class creates a virtual RPSGame which allows the user 
**				to play a game of Rock, Paper, Scissors against the computer.
**				The class uses data members to keep track of the score and ties
**				as well as create the "Tools" for the game. The class also
**				contains functions allowing the user to change their tool type,
**				and change the strength of the tools. 
*********************************************************************/

#ifndef RPS_GAME_HPP
#define RPS_GAME_HPP

#include "Scissors.hpp"
#include "Paper.hpp"
#include "Rock.hpp"
#include "InputValidation.hpp"

#include <string>
#include <iostream>
#include <random>

class RPSGame
{

private:

	int computerWins;
	int humanWins;
	int ties;
    int lastTool;
    int **moveHistoryMatrix;
    char* moveCandidates;
    
    int customRockStrength;
    int customPaperStrength;
    int customScissorStrength;
    
    bool shouldUseCustomStrengthsForUser;
    bool shouldUseCustomStrengthsForAi;

	Tool* computerTool;
	Tool* userTool;
    
    void setUpGame(); //configure custom tool strengths
    void createTool(Tool **tool, char toolType, bool shouldUseCustomStrength); //initialize tool pointers
    int getUserStrengthValue(std::string msg); //get tool strength value from user
    char computerSelectionRandom(); //computer algorithm for choosing tool
    char computerSelectionProbabilityBased(); //computer algorithm for choosing tool
    
    char userSelectionRps(); //ask user to choose tool
    char userSelectionYn(std::string msg);
    
    int getColumnForTool(char c);
public:

	RPSGame();
	void playGame();
	~RPSGame();
};

#endif
