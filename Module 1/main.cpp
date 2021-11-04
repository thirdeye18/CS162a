/*********************************************************************
** Program name: Lab1
** Filename: main.cpp
** Author: Justin Hammel
** Date: 4/10/2017
** Description: This is the main function for using the readMatrix
**				and determinant functions. It will ask the user to
**				either input a 2x2 or 3x3 matrix from which the 
**				determinant will be calculated. The 2d array is 
**				displayed in matrix form and the determinant is also 
**				displayed on the screen.
*********************************************************************/
#include <iostream>
#include <string>
#include "readMatrix.hpp"
#include "determinant.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stoi;

bool inputValidation(string);

int main()
{
	cout << "How large of a matrix would you like to use?" << endl;
	cout << "Enter 2 for a 2x2 matrix, enter 3 for a 3x3 matrix";
	cout << endl;

	string userInput = "";
	getline(cin, userInput);

	//loop to control user input validation
	while (!inputValidation(userInput))
	{
		cout << "Invalid input" << endl;
		cout << "Enter 2 for a 2x2 matrix, enter 3 for a 3x3 matrix";
		cout << endl;
		userInput = "";
		getline(cin, userInput);
	}

	//convert string input to integer value
	int matrixSize = stoi(userInput);

	//create new matrix pointer
	int** matrix = new int* [matrixSize];
	for (int row = 0; row < matrixSize; row++)
	{
		matrix[row] = new int[matrixSize];
	}

	//fill array with 0
	for (int row = 0; row < matrixSize; row++)
	{
		for (int col = 0; col <matrixSize; col++)
		{
			matrix[row][col] = 0;
		}
	}

	//output array values
	for (int row = 0; row < matrixSize; row++)
	{
		for (int col = 0; col <matrixSize; col++)
		{
			cout << matrix[row][col];
		}
	}
	cout << endl;

	readMatrix(matrix, matrixSize);
	cout << endl;

	//output first row array values
	for (int row = 0; row < matrixSize; row++)
	{
		for (int col = 0; col <matrixSize; col++)
		{
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
	
	cout << endl << "The determinant of the matrix is: ";
	cout << determinant(matrix, matrixSize) << endl;

	//From http://stackoverflow.com/questions/936687/
	//how-do-i-declare-a-2d-array-in-c-using-new
	for (int i = 0; i < matrixSize; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	
	return 0;
}

/*Validates user input checking for an integer. User input is passed 
to the function as a string which is then checked using a for loop
to step through the strings characters verifying if they are numbers.
Returns true if valid input is detected. The function will also check
to see if the string is blank. End of the function also tests if the 
value entered is a 2 or a 3.*/

bool inputValidation(string inputString)
{

	if (inputString.length() == 0)
		return false;
	for (size_t count = 0; count < inputString.length(); count ++)
		if (!isdigit(inputString[count]))
		{
			return false;
		}
	int size = stoi(inputString);
	if (size != 2 && size != 3)
	{
		return false;
	}
	return true;
}
