/*********************************************************************
** Program name: Project1
** Filename: Board.cpp
** Author: Justin Hammel
** Date: 4/15/2017
** Description: This is my main for running general programs and
**				testing.
********************************************************************/
#include <iostream>
#include <iomanip>

/* #include <chrono>
#include <thread> */

#include "Board.hpp"

using std::cout;
using std::endl;

Board::Board(int rowIn, int colIn)
{
	boardLayout = new char*[row];
	for(int i = 0; i < row; ++i)
	{
		boardLayout[i] = new char[col];
	}
}

void Board::setRow(int rowStore)
{
	row = rowStore;
}

void Board::setCol(int colStore)
{
	col = colStore;
}

int Board::getRow()
{
	return row;
}

int Board::getCol()
{
	return col;
}	

void Board::print()
{
	for(int i = 0; i < row; ++i) 
	{
		for(int j = 0; j < col; ++j) 
		{
			cout << boardLayout[i][j];
		}
		cout << endl;
	}
}

void Board::fill()
{
	for(int i = 0; i < row; ++i) 
	{
		for(int j = 0; j < col; ++j) 
		{
			boardLayout[i][j] = '#';
		}
	}
}

void Board::clearScreen()
{
	std::cout << "\033[2J\033[1;1H";
}

void Board::freeMemory(int freeRow)
{
	for(int i = 0; i < freeRow; ++i) 
	{
		delete [] boardLayout[i];
	}
	delete [] boardLayout;
}