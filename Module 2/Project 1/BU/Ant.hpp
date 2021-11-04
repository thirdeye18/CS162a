/*********************************************************************
** Program name: Project1
** Filename: Ant.hpp
** Author: Justin Hammel
** Date: 4/15/2017
** Description: This is the implementation for the game class.
*********************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

enum Direction {UP, DOWN, LEFT, RIGHT};

class Ant
{

private:
	int antX;
	int antY;
	
public:
	void whiteMove();
	void blackMove();
	
};

#endif