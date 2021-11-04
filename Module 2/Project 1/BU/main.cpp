/*********************************************************************
** Program name: Project1
** Filename: Main.cpp
** Author: Justin Hammel
** Date: 4/15/2017
** Description: This is my main for running general programs and
**				testing.
*********************************************************************/
#include <iostream>
/* #include <chrono>
#include <thread>
 */
#include "Board.hpp"
#include "Ant.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int userRow, userCol = 0;
	
	cout << "Please limit rows and columns to 80\n";
	cout << "How many rows would you like the board to be?\n";
	cin >> userRow;
	cout << "How many columns would you like the board to be?\n";
	cin >> userCol;
	cout << endl;
	cin.ignore();
	
	Board currentBoard (userRow, userCol);
	
	currentBoard.setRow(userRow);
	currentBoard.setCol(userCol);
	
	currentBoard.fill();
	
	currentBoard.print();
	
	cout << "Press enter to continue\n";
	cin.get();
	
	//std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	
	currentBoard.clearScreen();
	
	cout << "Press enter to continue\n";
	cin.get();
	
	cout << userRow;
	
	currentBoard.freeMemory(userRow);
		
	return 0;
}