/*********************************************************************
** Program name: Project1
** Filename: Board.hpp
** Author: Justin Hammel
** Date: 4/15/2017
** Description: This is the implementation for the game class.
*********************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{

private:
	int row;
	int col;
	char **boardLayout;
	
public:
	//Constructor
	Board(int, int);
	
	//setters
	void setRow(int);
	void setCol(int);
	
	//getters
	int getRow();
	int getCol();
	
	void print();
	void fill();
	void clearScreen();
	void freeMemory(int);
		
};

#endif