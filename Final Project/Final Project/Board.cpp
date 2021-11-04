/*********************************************************************
** Program name: Final Project
** Filename: Board.cpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: Board class that will store the spaces in a map. Key 
**				for the map items will be a structure called location
**				representing an ordered pair.  Data stored in the map 
**				is a pointer to the Space objects.
*********************************************************************/

#include "Board.hpp"

/*Constructors*/

Board::Board()
{
	for (size_t i = 0; i < 19; i++)
	{
		for (size_t j = 0; j < 19; j++)
		{
			boardLayout[i][j] = nullptr;
		}
	}
	spaceCount = 0;
	totalTiles = 19;
	gemRooms = 4;
	addStart();
	addSpace(8, 9, LEFT, RIGHT, boardLayout[9][9]);
	addSpace(9, 10, RIGHT, LEFT, boardLayout[9][9]);
	addSpace(10, 10, UP, DOWN, boardLayout[9][10]);
	addSpace(8, 8, DOWN, UP, boardLayout[8][9]);
	addSpace(10, 9, LEFT, RIGHT, boardLayout[10][10]);
}

/*Destructor*/

Board::~Board()
{
	for (size_t i = 0; i < 19; i++)
	{
		for (size_t j = 0; j < 19; j++)
		{
			if (boardLayout[i][j])
			{
				delete boardLayout[i][j];
				boardLayout[i][j] = nullptr;
			}
		}
	}
}

/*Getters for board parameters.*/

int Board::getSpaceCount()
{
	return spaceCount;
}

int Board::getTotalTiles()
{
	return totalTiles;
}

int Board::getGemRooms()
{
	return gemRooms;
}

/*Steps through the array printing out the contents that are not 
nullptr.*/

void Board::printBoard()
{
	for (size_t i = 0; i < 19; i++)
	{
		for (size_t j = 0; j < 19; j++)
		{
			if (boardLayout[i][j])
			{
				boardLayout[i][j]->printSpace();
			}
		}
	}
}

/*Adds the start tile to the map.*/

void Board::addStart()
{
	makeSpace = new StartSpace;
	boardLayout[9][9] = makeSpace;
	spaceCount = 1;
	totalTiles = 18;
}

/*Used to add other tiles to the map.*/

void Board::addSpace(int cX, int cY, Direction eDir, Direction iDir, Space* start)
{
	//makeSpace = makeSpace->generateSpace(inDir);

	//adjust tile and active space counts
	//if (spaceType == 2)
	//{
	//	gemRooms -= 1;	//adjust available number of gem rooms
	//}
	spaceCount += 1;
	totalTiles - +1;

	//assigns new space exits if to existing rooms
	//makeSpace->makePaths(inDir, fromSpace, outDir);
	//boardLayout[sX][sY] = makeSpace;
}