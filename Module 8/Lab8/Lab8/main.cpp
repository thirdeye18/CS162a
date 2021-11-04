/*********************************************************************
** Program name: Lab 8
** Filename: main.cpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: Main for the implementation of my search and sort   
**				functions. This will create the menu for running the
**				functions or exiting the program. 
*********************************************************************/

#include <iostream>
#include <fstream>

//#include<vld.h>

#include "InputValidation.hpp"
#include "Menu.hpp"
#include "SearchSort.hpp"

using std::ofstream;
using std::ifstream;

const int MENU_OPTIONS = 4;
const size_t SIZE = 100;

void fillArrays(int ary1[SIZE], int ary2[SIZE], int ary3[SIZE], 
	int ary4[SIZE]);

void fillBinArrays(int ary[SIZE], string fillFile);

void clearArrays(int ary1[SIZE], int ary2[SIZE], int ary3[SIZE],
	int ary4[SIZE]);

void displayArray(const int ary[SIZE], size_t size);

void createTxt(const int ary[SIZE], size_t size);

int main()
{
	//generating the main menu
	Menu mainMenu("MainMenuOptions.txt");

	int choice = 0;

	//setting up arrays to hold int values
	int array1[SIZE],
		array2[SIZE],
		array3[SIZE],
		array4[SIZE];

	while (choice != MENU_OPTIONS)
	{
		mainMenu.printMenu();
		cout << endl;
		cout << "Please select an option from the menu.\n";
		choice = mainMenu.userChoice();
		
		string searchString = "";
		int search;

		switch (choice)
		{
		case 1://non-binary search
		{
			//filling the arrays from the files
			fillArrays(array1, array2, array3, array4);
			
			//getting input for the search value
			cout << "What number would you like to search for?\n";
			getline(cin, searchString);
			while (!integerValidation(searchString))
			{
				cout << "Please enter a valid integer to search for.\n";
				searchString = "";
				getline(cin, searchString);
			}
			search = stringToInt(searchString);

			//Getting the results of the search and displaying them
			int result1 = -1;
			int result2 = -1;
			int result3 = -1;
			int result4 = -1;

			//file 1 results
			result1 = linearSearch(array1, SIZE, search);
			if (result1 == -1)
			{
				cout << "Search term not found in file 1.\n";
			}
			else
			{
				cout << "Search term found at position " << result1 << ".\n";
			}

			//file 2 results
			result2 = linearSearch(array2, SIZE, search);
			if (result2 == -1)
			{
				cout << "Search term not found in file 2.\n";
			}
			else
			{
				cout << "Search term found at position " << result2 << ".\n";
			}

			//file 3 results
			result3 = linearSearch(array3, SIZE, search);
			if (result3 == -1)
			{
				cout << "Search term not found in file 3.\n";
			}
			else
			{
				cout << "Search term found at position " << result3 << ".\n";
			}

			//file 4 results
			result4 = linearSearch(array4, SIZE, search);
			if (result4 == -1)
			{
				cout << "Search term not found in file 4.\n";
			}
			else
			{
				cout << "Search term found at position " << result4 << ".\n";
			}

			clearArrays(array1, array2, array3, array4);

			break;
		}
		case 2://Sort
		{
			//filling the arrays from the files
			fillArrays(array1, array2, array3, array4);

			//sorting all the arrays
			bubbleSort(array1, SIZE);
			cout << "Please enter output file name for first sorted list.\n";
			createTxt(array1, SIZE);

			bubbleSort(array2, SIZE);
			cout << "Please enter output file name for second sorted list.\n";
			createTxt(array2, SIZE);

			bubbleSort(array3, SIZE);
			cout << "Please enter output file name for third sorted list.\n";
			createTxt(array3, SIZE);

			bubbleSort(array4, SIZE);
			cout << "Please enter output file name for fourth sorted list.\n";
			createTxt(array4, SIZE);

			clearArrays(array1, array2, array3, array4);

			break;
		}
		case 3://binary search
		{
			//filling the arrays with the sorted values from the text files
			fillBinArrays(array1, "test1.txt");
			fillBinArrays(array2, "test2.txt");
			fillBinArrays(array3, "test3.txt");
			fillBinArrays(array4, "test4.txt");

			//getting input for the search value
			cout << "What number would you like to search for?\n";
			getline(cin, searchString);
			while (!integerValidation(searchString))
			{
				cout << "Please enter a valid integer to search for.\n";
				searchString = "";
				getline(cin, searchString);
			}
			search = stringToInt(searchString);

			//Getting the results of the search and displaying them
			int result1 = -1;
			int result2 = -1;
			int result3 = -1;
			int result4 = -1;

			//file 1 results
			result1 = binarySearch(array1, SIZE, search);
			if (result1 == -1)
			{
				cout << "Search term not found in file 1.\n";
			}
			else
			{
				cout << "Search term found at position " << result1 << ".\n";
			}

			//file 2 results
			result2 = binarySearch(array2, SIZE, search);
			if (result2 == -1)
			{
				cout << "Search term not found in file 2.\n";
			}
			else
			{
				cout << "Search term found at position " << result2 << ".\n";
			}

			//file 3 results
			result3 = binarySearch(array3, SIZE, search);
			if (result3 == -1)
			{
				cout << "Search term not found in file 3.\n";
			}
			else
			{
				cout << "Search term found at position " << result3 << ".\n";
			}

			//file 4 results
			result4 = binarySearch(array4, SIZE, search);
			if (result4 == -1)
			{
				cout << "Search term not found in file 4.\n";
			}
			else
			{
				cout << "Search term found at position " << result4 << ".\n";
			}

			clearArrays(array1, array2, array3, array4);

			break;
		}

		case 4://Exit

			cout << "Exiting the program\n";
			break;

		default://invalid menu option

			cout << "Invalid menu choice! Please try again\n";
			mainMenu.clearScreen();

		}

	}

	return 0;
}

/*Filling arrays to be used by the various functions*/

void fillArrays(int ary1[SIZE], int ary2[SIZE], int ary3[SIZE], 
	int ary4[SIZE])
{
	//setup objects to read text file
	fstream searchFile1;
	fstream searchFile2;
	fstream searchFile3;
	fstream searchFile4;

	//open text files
	searchFile1.open("searchFileBegin.txt", ios::in);
	searchFile2.open("searchFileEnd.txt", ios::in);
	searchFile3.open("searchFileMid.txt", ios::in);
	searchFile4.open("searchFileNone.txt", ios::in);

	//Verify file exists
	if (!searchFile1)
	{
		cout << "Unable to find searchFileBegin.txt\n";
	}
	if (!searchFile2)
	{
		cout << "Unable to find searchFileEnd.txt\n";
	}
	if (!searchFile3)
	{
		cout << "Unable to find searchFileMid.txt\n";
	}
	if (!searchFile4)
	{
		cout << "Unable to find searchFileNone.txt\n";
	}

	//filling arrays with text values
	for (size_t i = 0; i < 100; i++)
	{
		searchFile1 >> ary1[i];
	}
	for (size_t i = 0; i < 100; i++)
	{
		searchFile2 >> ary2[i];
	}
	for (size_t i = 0; i < 100; i++)
	{
		searchFile3 >> ary3[i];
	}
	for (size_t i = 0; i < 100; i++)
	{
		searchFile4 >> ary4[i];
	}

	//closing files
	searchFile1.close();
	searchFile2.close();
	searchFile3.close();
	searchFile4.close();
}

/*Method to fill the arrays for the binary search.  Allows more 
flexibility by allowing the name of the file being read from to 
be passed as a parameter.*/

void fillBinArrays(int ary[SIZE], string fillFile)
{
	ifstream inputFile;

	inputFile.open(fillFile);

	if (!inputFile)
	{
		cout << "Unable to find " << fillFile << "\n";
	}

	for (size_t i = 0; i < SIZE; i++)
	{
		inputFile >> ary[i];
	}

	inputFile.close();
}

/*Sets array values to 0 for reuse.*/

void clearArrays(int ary1[SIZE], int ary2[SIZE], int ary3[SIZE], int ary4[SIZE])
{
	for (size_t i = 0; i < 100; i++)
	{
		ary1[i] = 0;
	}
	for (size_t i = 0; i < 100; i++)
	{
		ary2[i] = 0;
	}
	for (size_t i = 0; i < 100; i++)
	{
		ary3[i] = 0;
	}
	for (size_t i = 0; i < 100; i++)
	{
		ary4[i] = 0;
	}
}

/*Function displays the contents of an array passed to it. Carriage return will be used
every 20 values displayed.*/

void displayArray(const int ary[SIZE], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << ary[i] << " ";
		if ((i + 1) % 20 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

/*Method to place the contents of an array into a text file.*/

void createTxt(const int ary[SIZE], size_t size)
{
	string fileName = "";

	getline(cin, fileName);
	while (!txtValidation(fileName))
	{
		cout << "Please enter a file name in the format name.txt\n";
		fileName = "";
		getline(cin, fileName);
	}

	//preparing output file object
	ofstream outputFile;

	//opening output file
	outputFile.open(fileName);

	//writing array values to the file
	for (size_t i = 0; i < size; i++)
	{
		outputFile << ary[i] << " ";
		if ((i + 1) % 5 == 0)
		{
			outputFile << "\n";
		}
	}

	//closing file
	outputFile.close();

	cout << "Write operation cmplete\n";
}
