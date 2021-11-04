/*********************************************************************
** Program name: Final Project
** Filename: Board.hpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the implementation for the Board class.
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <map>

#include "Space.hpp"
#include "StartSpace.hpp"
#include "ExitSpace.hpp"
#include "GemSpace.hpp"
#include "StandardSpace.hpp"
#include "TreasureSpace.hpp"

using std::cout;
using std::endl;

class Board
{
protected:
	Space* boardLayout[19][19];
	Space* makeSpace = nullptr;

	int spaceCount;
	int totalTiles;
	int gemRooms;

public:
	Board();
	~Board();

	int getSpaceCount();
	int getTotalTiles();
	int getGemRooms();

	void printBoard();

	void addStart();
	void addSpace(int cX, int cY, Direction eDir, Direction iDir, Space* start);
};

#endif