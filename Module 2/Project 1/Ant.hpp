/*********************************************************************
** Program name: Project1
** Filename: Ant.hpp
** Author: Justin Hammel
** Date: 4/17/2017
** Description: This is the implementation for the Ant class.
*********************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

#include "Board.hpp"

enum Direction { UP = 1, RIGHT, DOWN, LEFT };

//forward declaration
class Board;

class Ant
{

private:
	int antRow;
	int antCol;
	int facing;

public:
	Ant();
	Ant(int, int, int);
	
	int getAntRow();
	int getAntCol();
	int getAntDirection();
	
	void setAntRow(int rowIn);
	void setAntCol(int colIn);
	
	bool squareState(char**);
	void whiteMove(char** boardIn);
	void blackMove(char** boardIn);
	void fwdAnt();
	void printAnt();

	
};

#endif
