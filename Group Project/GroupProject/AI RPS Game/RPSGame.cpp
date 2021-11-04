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

#include "RPSGame.hpp"

/*********************************************************************
** Description: Default constructor which sets the human wins,
**				computer wins, and ties to 0
*********************************************************************/
RPSGame::RPSGame()  {

	this->computerWins = 0;
	this->humanWins = 0;
	this->ties = 0;
    this->shouldUseCustomStrengthsForUser = false;
    this->shouldUseCustomStrengthsForAi = false;
    this->lastTool = -1;
    this->moveHistoryMatrix = new int*[3];
    
    for (int i = 0; i < 3; i++) {
        moveHistoryMatrix[i] = new int[3];
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            moveHistoryMatrix[i][j] = 0;
        }
    }
}

/*********************************************************************
 ** Description: Ask user for custom Tool strengths
 **
 *********************************************************************/
void RPSGame::setUpGame() {
    //prompt user for custom strengths
    if (userSelectionYn("Welcome to Rock, Paper, Scissors! Do you want to choose different strengths for the tools? (y-yes, n-no)") == 'Y'){
        shouldUseCustomStrengthsForUser = true;
        customRockStrength = getUserStrengthValue("rock");
        customPaperStrength = getUserStrengthValue("paper");
        customScissorStrength = getUserStrengthValue("scissors");
        
        //should the computer use the custom or default values?
        if (userSelectionYn("Should the computer use custom strengths for the tools? (y-yes, n-no)") == 'Y') {
            shouldUseCustomStrengthsForAi = true;
        }
    }
}

/*********************************************************************
** Description: Plays a game of rock paper scissors
**
*********************************************************************/
void RPSGame::playGame() {
    
    setUpGame();
    
	bool quitGame = false;

	//until the user chooses to quit the game, continually asks the user
	//for a new tool and plays a game of rock paper scissors
	while (!quitGame) {
        
		char userToolChoice = userSelectionRps();
        
        char computerToolChoice;
        if (lastTool != -1) {
            computerToolChoice = computerSelectionProbabilityBased();
        } else {
            computerToolChoice = computerSelectionRandom();
        }
    
        //if the user did not choose to exit, plays game
        if (userToolChoice != 'E') {
            
            createTool(&userTool, userToolChoice, shouldUseCustomStrengthsForUser);
            
            createTool(&computerTool, computerToolChoice, shouldUseCustomStrengthsForAi);
            std::cout << "Computer chose " << computerTool->getType() << std::endl;

            //gets the outcome of the fight
            //updates scores and displays round information
            //based on who won the fight
            switch (userTool->fight(computerTool)) {
                case USER_WON:
                    this->humanWins++;
                    std::cout << "You win!" << std::endl;
                    break;
                case COMPUTER_WON:
                    this->computerWins++;
                    std::cout << "Computer wins!" << std::endl;
                    break;
                case DRAW:
                    this->ties++;
                    std::cout << "Draw!" << std::endl;
                    break;
            }
            
            
            int columnForCurrentTool = getColumnForTool(userToolChoice);
            printf("column %d, row %d\n", columnForCurrentTool, lastTool);
            //increment index of current type
            if (lastTool != -1) {
                moveHistoryMatrix[lastTool][columnForCurrentTool]++;
            }
            
            //print move matrix
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf("%d ", moveHistoryMatrix[i][j]);
                }
                printf("\n");
            }
            
            //check user's last tool type
            lastTool = getColumnForTool(userToolChoice);
            
            std::cout << "Human wins: " << this->humanWins << "\n" << "Computer wins: " << this->computerWins << "\n" << "Ties: " << this->ties << std::endl;
            
            //deallocates memory
            delete userTool;
            delete computerTool;
        }
        
        else {
            
            quitGame = true;
        }
    }
}

/*********************************************************************
 ** Description: Gets and returns the user's choice of tool at the
 **              beginning of each game
 *********************************************************************/
void RPSGame::createTool(Tool **toolPtr, char toolType, bool shouldUseCustomStrength) {
    //initialize toolPtr depending on toolType
    //use custom strength values if shouldUseCustomStrength==true
    switch(toolType) {
        case 'r':
            if (shouldUseCustomStrength) {
                *toolPtr = new Rock(this->customRockStrength);
            } else {
                *toolPtr = new Rock();
            }
            break;
        case 'p':
            if (shouldUseCustomStrength) {
                *toolPtr = new Paper(this->customPaperStrength);
            } else {
                *toolPtr = new Paper();
            }
            break;
        case 's':
            if (shouldUseCustomStrength) {
                *toolPtr = new Scissors(this->customScissorStrength);
            } else {
                *toolPtr = new Scissors();
            }
            break;
    }
}

/*********************************************************************
** Description: Gets and returns the user's choice of tool at the
**              beginning of each game
*********************************************************************/
char RPSGame::userSelectionRps() {
	char userChoice = ' ';
    std::cout << "Choose your tool (r-rock, p-paper, s-scissor, e-exit): " << std::endl;
    get_tool_type_and_validate(userChoice);
    return userChoice;
}

/*********************************************************************
 ** Description: Gets and returns the user's y (yes) or n (no) choice
 *********************************************************************/
char RPSGame::userSelectionYn(std::string msg) {
    char userChoice = ' ';
    std::cout << msg << std::endl;
	get_y_n_input_and_validate(userChoice);
    
    return userChoice;
}

/*********************************************************************
 ** Description: Gets and returns the an integer from the user
 *********************************************************************/
int RPSGame::getUserStrengthValue(std::string msg) {
    int userChoice = 0;
    std::cout << "Choose strength for " << msg << " (must be an integer): " << std::endl;
	get_int_input_and_validate(userChoice);
    return userChoice;
}

/*********************************************************************
** Description: Returns the computer's tool selection. Looks up the
** user's last moves in the move matrix. Gets the highest occuring
** values and determines the next move.
*********************************************************************/
char RPSGame::computerSelectionProbabilityBased() {

	char computerChoice;
    
    //start at column 0
    int max = moveHistoryMatrix[lastTool][0];
    int moveCandidateCount = 0;
    moveCandidates = new char[3];

    //get highest frequenc(ies) in row
    printf("Row: ");
        for (int i = 0; i < 3; i++) {
        printf("%d ", moveHistoryMatrix[lastTool][i]);
        if (moveHistoryMatrix[lastTool][i] > max) {
            max = moveHistoryMatrix[lastTool][i];
        }
    }
    printf("\n");
    
    //compare highest frequency value to items in list, store matches in moveCandidates
    for (int i = 0; i < 3; i++) {
        if (moveHistoryMatrix[lastTool][i] == max) {
            moveCandidates[moveCandidateCount++] = i;
        }
    }
    
    for (int i = 0; i < moveCandidateCount; i ++) {
        printf("Move candidates are %d\n", moveCandidates[i]);
    }
    
    //generate random index based on number of move candidates
    int index = rand() % moveCandidateCount;
    int c = moveCandidates[index];
    
    switch (c) {
        case 0:
            computerChoice = 'p';
            break;
        case 1:
            computerChoice = 's';
            break;
        case 2:
            computerChoice = 'r';
            break;
    }

	return computerChoice;
	
}

/*********************************************************************
 ** Description: Returns the computer's tool selection.
 *********************************************************************/
char RPSGame::computerSelectionRandom() {
    
    char computerChoice = 's';
    
    //generates a random number to assign the computer tool
    //randomly assigns the computer a tool
    int randomTool = rand() % 3 + 1;
    
    if (randomTool == 1) {
        computerChoice = 'r';
    } else if (randomTool == 2) {
        computerChoice = 'p';
    }
    else {
        computerChoice = 's';
    }
    return computerChoice;
}

int RPSGame::getColumnForTool(char c) {
    switch (c) {
        case 'r':
            return 0;
            break;
        case 'p':
            return 1;
            break;
        case 's':
            return 2;
            break;
    }
    return -1;
}

/*********************************************************************
** Description: Destructor which deletes the memory allocated for
**				the tools and sets the pointers to null
*********************************************************************/
RPSGame::~RPSGame() {
	userTool = nullptr;
	computerTool = nullptr;
    for(int i = 0; i < 3; i++) {
        delete [] moveHistoryMatrix[i];
    }
    delete [] moveHistoryMatrix;
    delete [] moveCandidates;
}
