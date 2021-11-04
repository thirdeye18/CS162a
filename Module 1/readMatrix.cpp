/*********************************************************************
** Program name: Lab1
** Filename: readMatrix.cpp
** Author: Justin Hammel
** Date: 4/10/2017
** Description: This function receives a 2x2 or 3x3 pointer of arrays
**				and the size of the array, either 2, or 3. The array 
**				passed to the function starts blank filled with zeros
**				from the main.  The 2d array is then filled using
**				user integer values.
*********************************************************************/
#include <iostream>
#include <string>
#include "readMatrix.hpp"

using std::cout;
using std::cin;
using std::string;
using std::endl;

void readMatrix(int** matrix, int size)
{
	if (size == 2)
	{
		cout << "Input the 4 values for the matrix (A-D)" << endl;
		cout << "|A B|\n";
		cout << "|C D|\n";
	}
	if (size == 3)
	{
		cout << "Input the 9 values for the matrix (A-I)" << endl;
		cout << "|A B C|\n";
		cout << "|D E F|\n";
		cout << "|G H I|\n";
	}

	//fill array with user inputed vales
	int userIn = 0;
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col <size; col++)
		{
			cin >> userIn;
			matrix[row][col] = userIn;
		}
	}

	/*loop to control user input validation
	while (!inputValidation(userInput))
	{
		cout << "Invalid input" << endl;
		cout << "Enter 2 for a 2x2 matrix, enter 3 for a 3x3 matrix";
		cout << endl;
		userInput = "";
		getline(cin, userInput);
	}*/
}

/*Validates user input checking for an integer. User input is passed
to the function as a string which is then checked using a for loop
to step through the strings characters verifying if they are numbers.
Returns true if valid input is detected. The function will also check
to see if the string is blank.

bool integerInputValidation(string inputString)
{

	if (inputString.length() == 0)
		return false;
	for (size_t count = 0; count < inputString.length(); count++)
		if (!isdigit(inputString[count]))
		{
			return false;
		}
	return true;
}*/
