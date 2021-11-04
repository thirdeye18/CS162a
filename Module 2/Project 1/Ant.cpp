/*********************************************************************
** Program name: Project1
** Filename: Ant.cpp
** Author: Justin Hammel
** Date: 4/17/2017
** Description: 
**
********************************************************************/
#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "Ant.hpp"
//#include "Board.hpp"

using std::cout;
using std::endl;



Ant::Ant()
{
	antRow = 0;
	antCol = 0;
	facing = 0;
}

Ant::Ant(int aRowin, int aColIn, int faceIn)
{
	antRow = aRowin;
	antCol = aColIn;
	facing = faceIn;
}

int Ant::getAntRow()
{
	return antRow;
}

int Ant::getAntCol()
{
	return antCol;
}

int Ant::getAntDirection()
{
	return facing;
}

void Ant::setAntRow(int rowIn)
{
	antRow = rowIn;
}

void Ant::setAntCol(int colIn)
{
	antCol = colIn;
}

bool Ant::squareState (char** boardIn)
{
	//squareState == true == white square
	if (boardIn[getAntRow()][getAntCol()] == '.')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Ant::whiteMove(char** boardIn)
{
	//turn the ant
	facing+=1;
	if (facing > 4)
	{
		facing = 1;
	}
	
	//change square color
	boardIn[antRow][antCol] = '#';
	//move ant forward
	fwdAnt();
}

void Ant::blackMove(char** boardIn)
{
	facing-=1;
	if (facing < 1)
	{
		facing = 4;
	}
	boardIn[antRow][antCol] = '.';
	fwdAnt();
}

void Ant::fwdAnt()
{
	if (facing == 1)
	{
		antRow-=1;
	}		
	else if (facing == 3)
	{
		antRow+=1;
	}
	else if (facing == 2)
	{
		antCol+=1;
	}
	else if (facing == 4)
	{
		antCol-=1;
	}
}

void Ant::printAnt()
{
	cout << "Row = " << antRow << endl;
	cout << "Col = " << antCol << endl;
	cout << "Facing = " << facing << endl;
}
