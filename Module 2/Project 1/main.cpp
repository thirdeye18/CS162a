/*********************************************************************
** Program name: Project1
** Filename: Main.cpp
** Author: Justin Hammel
** Date: 4/17/2017
** Description: This is my main for running the Langston's Ant sim
**		for Project 1.  Further documentation for functions
**		is shown as comments before associated functions.

*********************************************************************/
#include <iostream>

#include "Board.hpp"
#include "Ant.hpp"
#include "Menu.hpp"
#include "InputValidation.hpp"

using std::cout;
using std::cin;
using std::endl;

int boardRowInput();
int boardColInput();
int roundsFunction();
int antRowInput(int validRow);
int antColInput(int validCol);
int antFacingInput();
int randomAntRow(int);
int randomAntCol(int);

int main()
{
	//Creating Menu object and printing menu
	Menu currentMenu;
	currentMenu.addOption();
	currentMenu.clearScreen();
	currentMenu.printMenu();

	bool isBoard = false;
	bool roundsEntered = false;
	string sChoice = "";
	int choice = 0;
	int userRounds = 0;
	Board* ptrBoard;
	Ant* ptrAnt;
	
	while (choice != 5)
	{	
		getline(cin, sChoice);
		while (!integerValidation(sChoice))
		{
			cout << "Invalid menu choice\n";
			getline(cin, sChoice);
		}
		choice = stringToInt(sChoice);

		if (choice == 1)//create board
		{
			currentMenu.clearScreen();
			ptrBoard = new Board(boardRowInput(), boardColInput());
			isBoard = true;
			currentMenu.clearScreen();
			currentMenu.printMenu();
		}
		
		else if (choice == 2)//set rounds
		{
			currentMenu.clearScreen();
			userRounds = roundsFunction();
			roundsEntered = true;
			currentMenu.clearScreen();
			currentMenu.printMenu();
		}
		
		else if (choice == 3)//start sim user ant
		{
			currentMenu.clearScreen();
			if (ptrBoard->validateParameters(isBoard, roundsEntered))
			{
				bool validAnt = false;
				int aR = antRowInput(ptrBoard->getRow());
				int aC = antColInput(ptrBoard->getCol());
				while (!validAnt)
				{			
					validAnt = ptrBoard->validAntPlace(aR, aC);
					if (!validAnt)
					{
						cout << "Ant placed outside array boundaries\n";
						cout << "Please try another row, col combination.\n";
						aR = antRowInput(ptrBoard->getRow());
						aC = antColInput(ptrBoard->getCol());
					}
				}
				int aF = antFacingInput();
				ptrAnt = new Ant(aR, aC, aF);
				ptrBoard->playLoop(ptrAnt, userRounds);
				currentMenu.printMenu();
				cin.ignore();
			}
			else
			{
				cout << "Simulation parameters not set\n";
				cout << "Please create board and set rounds";
				cout << " prior to running simulation.\n";
				currentMenu.printMenu();
			} 
		}
		
		else if (choice == 4)//start sim random ant
		{
			//used as a quick way to test running sim
			currentMenu.clearScreen();
			if (!isBoard && !roundsEntered)
			{
				cout << "Please generate board and enter rounds first\n";
			}
			else
			{
				cout << "Function not working.\n";
/* 				int rBRow = ptrBoard->getRow;
				int rBCol = ptrBoard->getCol;
				int rAnt = randomAntRow(rBRow);
				int rCol = randomAntCol(rBCol);
				ptrAnt = new Ant(rAnt, rCol, 1);
				ptrBoard->playLoop(ptrAnt, userRounds); */
			}
			currentMenu.printMenu();
		}
		
		else if (choice == 5)//exit program
		{
			cout << "Goodbye\n";
		}
		
		else//improper menu use
		{
			cout << "Invalid menu input, try again\n";
		}
	}

	delete ptrAnt;
	delete ptrBoard;
	return 0;
}



/*Two functions, boardRowInput and boardColInput get and validate the 
  integer input from the user to create the 2d board array using the 
  rows and column values supplied. Integer values will be passed 
  back for use as parameters in creating Board objets. */

int boardRowInput()
{
	string userRow, userCol = "";
	cout << "Please limit rows and columns to 80\n";
	cout << "How many rows would you like the board to be?\n";
	getline(cin, userRow);
	while (!integerValidation(userRow))
	{
		cout << "Invalid input, please enter an integer value\n";
		userRow = "";
		getline(cin, userRow);
	}
	//converting strings to int
	int conRow = stringToInt(userRow);
	return conRow;
}

int boardColInput()
{
	string userCol = "";
	cout << "How many columns would you like the board to be?\n";
	getline(cin, userCol);
	while (!integerValidation(userCol))
	{
		cout << "Invalid input, please enter an integer value\n";
		userCol = "";
		getline(cin, userCol);
	}
	//converting strings to int
	int conCol = stringToInt(userCol);
	return conCol;
}

/*This function get the integer input from the user for the number of
  rounds the simulation will run. Input validation will verify that 
  integer input has been received.*/

int roundsFunction()
{
	string userRounds = "";
	cout << "How many rounds would you like the simulation to run?\n";
	getline(cin, userRounds);
	while (!integerValidation(userRounds))
	{
		cout << "Invalid input, please enter an integer value\n";
		userRounds = "";
		getline(cin, userRounds);
	}

	//converting strings to int
	int conRounds = stringToInt(userRounds);

	return conRounds;
}

/*Next three functions get the integer input from the user for the row,  
  column, and facing direction to place the ant in. Input validation 
  will verify that integer input has been received and that the direction
  is valid.*/

int antRowInput(int validRow)
{
	string userAntRow = "";	
	
	cout << "What row would you like the ant to start at?\n";
	cout << "Rows are positive integers from 0 to < ";
	cout << validRow << endl;
	getline(cin, userAntRow);
	
	while (!integerValidation(userAntRow))
	{
		cout << "Invalid input, please enter an integer value\n";
		userAntRow = "";
		getline(cin, userAntRow);
	}
	int conAntRow = stringToInt(userAntRow);
	
	return conAntRow;
}

int antColInput(int validCol)
{
	string userAntCol = "";
	
	cout << "What column would you like the ant to start at?\n";
	cout << "Columns are positive integers from 0 to < ";
	cout << validCol << endl;
	getline(cin, userAntCol);
	while (!integerValidation(userAntCol))
	{
		cout << "Invalid input, please enter an integer value\n";
		userAntCol = "";
		getline(cin, userAntCol);
	}
	int conAntCol = stringToInt(userAntCol);
	
	return conAntCol;
}

int antFacingInput()
{
	string userAntFace = "";
	
	cout << "What direction would you like the ant to start facing?\n";
	cout << "Up = 1, Right = 2, Down = 3, Left = 4\n";
	getline(cin, userAntFace);
	while (!integerValidation(userAntFace) || !directionValidation(userAntFace))
	{
		cout << "Invalid input, please enter an integer value\n";
		cout << " that is 1-4\n";
		userAntFace = "";
		getline(cin, userAntFace);
	}
	int conAntFace = stringToInt(userAntFace);
	
	return conAntFace;
}

int randomAntRow(int boardRow)
{
	unsigned seed = time(0);
	srand(seed);
	int randRow = 0;
	int randCol = 0;
	randRow = (rand() % (boardRow + 1));
	cout << randRow << endl;
	return randRow;
}

int randomAntCol(int boardCol)
{
	unsigned seed = time(0);
	srand(seed);
	int randRow = 0;
	int randCol = 0;
	randCol = (rand() % (boardCol + 1));
	cout << randCol << endl;
	return randCol;
}	
	


