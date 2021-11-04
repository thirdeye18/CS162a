/*********************************************************************
** Program name: Project1
** Filename: Board.cpp
** Author: Justin Hammel
** Date: 4/17/2017
** Description: This contains all the function for the Board class.
**				All constructors, destructors, and assignment 
**				overloads were adapted from textbook.  Some help for
**				creating rule of five copy methods was found in 
**				en.cppreference.com/w/cpp/language/rule_of_three .
**				I chose to add this-> to pretty much everything
**				as I was having difficulties tracking down faults.
**				I plan on working to find out if this is necessary.
********************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>

#include "Board.hpp"
//#include "Ant.hpp"

using std::cout;
using std::endl;
using std::cin;

/* Default constructor*/

Board::Board()
{
	row = 0;
	col = 0;
	boardLayout = NULL;
}

/* Constructor with parameters */

Board::Board(int rowIn, int colIn)
{
	row = rowIn;
	col = colIn;
	boardLayout = new char*[row];
	for (int i = 0; i < row; i++)
	{
		boardLayout[i] = new char[col];
	}
	//filling board
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			boardLayout[i][j] = '#';
		}
	}
}

/* Destructor */

Board::~Board()
{
	if (boardLayout)
	{
		for (int i = 0; i < row; i++)
		{
			delete[] boardLayout[i];
		}
		delete[] boardLayout;
	}
}

int Board::getRow()
{
	return row;
}

int Board::getCol()
{
	return col;
}

bool Board::validateParameters(bool bCreate, bool rEnter)
{
	if (bCreate == true && rEnter == true)
	{
		return true;
	}
	return false;
}

bool Board::validAntPlace (int rowCheck, int colCheck)
{
	if (rowCheck < 0 || rowCheck > getRow())
	{
		return false;
	}
	else if (colCheck < 0 || colCheck > getCol())
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Board::print()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << this->boardLayout[i][j];
		}
		cout << endl;
	}
}

void Board::fill()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			boardLayout[i][j] = '.';
		}
	}
}

void Board::clearScreen()
{
	std::cout << "\033[2J\033[1;1H";
}

void Board::playLoop(Ant* antIn, int rounds)
{
	//fill the board with white spaces, used . for visibility
	fill();
	clearScreen();
	
	char temp = ' ';

	for (int i = 1; i <= rounds; ++i)
	{
		clearScreen();
		int tempRow = antIn->getAntRow();
		int tempCol = antIn->getAntCol();
		temp = boardLayout[tempRow][tempCol];
		boardLayout[tempRow][tempCol] = '@';
		print();
		if (temp == '.')
		{
			antIn->whiteMove(boardLayout);
			edgeBump(antIn);
		}
		else
		{
			antIn->blackMove(boardLayout);
			edgeBump(antIn);			
		}
		usleep(250000);

	}
}

void Board::edgeBump(Ant* antIn)
{
	
	if (antIn->getAntRow() > getRow())
	{
		antIn->setAntRow(0);
	}
	else if (antIn->getAntCol() > getCol())
	{
		antIn->setAntCol(0);
	}
	else if (antIn->getAntRow() < 0)
	{
		antIn->setAntRow(getRow());
	}
	else if (antIn->getAntCol() < 0)
	{
		antIn->setAntCol(getCol());
	}
}
