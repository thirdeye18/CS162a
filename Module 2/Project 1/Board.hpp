/*********************************************************************
** Program name: Project1
** Filename: Board.hpp
** Author: Justin Hammel
** Date: 4/17/2017
** Description: This is the implementation for the Board class.
*********************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

#include "Ant.hpp"

//forward declaration
class Ant;

class Board
{

private:
	int row;
	int col;
	char** boardLayout;

public:
	//Constructors
	Board();
	Board(int, int);

	//Destructor
	~Board();
	
	//getters
	int getRow();
	int getCol();

	bool validateParameters(bool, bool);
	bool validAntPlace (int, int);
	void print();
	void fill();
	void clearScreen();
	void playLoop(Ant*, int);
	void edgeBump(Ant*);
	
};

#endif