/*********************************************************************
** Program name: Final Project
** Filename: Space.hpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the implementation file for the abstract 
**				Space class.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

enum Direction {UP, DOWN, LEFT, RIGHT};

#include <fstream>
#include <string>
#include <iostream>

using std::string;
using std::ifstream;
using std::ios;
using std::cout;
using std::endl;

class Space
{
protected:
	string layout[7];
	string spaceName;
	char travel1;
	char travel2;
	int spaceX;
	int spaceY;
	Space* exits[4];

public:
	Space();
	virtual ~Space();

	virtual void activate() = 0;
	virtual void explore(int eX, int eY) = 0;

	char randIcon(int choices);
	void fillSpace(string spaceLayoutFile);
	void spaceEntrance(Direction in);	//only used for exit space

	//connects spaces
	bool makePaths(Direction exit, Space* s, Direction to);

	//int spacePicker(Board* layout);
	//Space* generateSpace(Board* layout, Direction in);

	void printSpace();

	void travel();

};

#endif // !SPACE_HPP


