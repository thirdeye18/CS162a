/*********************************************************************
** Program name: Lab 8
** Filename: main.cpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: Contains the methods for the search and sort lab 8 
**				algorithms. The non-binary search function uses a 
**				linear search method from the text. The sort function 
**				is a bubble sort from the text. The binary search 
**				used is adapted from the Searching ppt.
*********************************************************************/

#include "SearchSort.hpp"

/*This uses the linear serach method from the text pg 604. It moves
through the array passed to it sequentially checking values against 
the search term. This will only work with the first time the value 
appears in the array being searched. Duplicates will not be flagged.
This search will return the value of the found terms subscript.*/

int linearSearch(const int list[], size_t size, int searchTerm)
{
	int index = 0;
	int position = -1;
	bool found = false;

	while (index < size && !found)
	{
		if (list[index] == searchTerm)
		{
			found = true;
			position = index;
		}
		index++;
	}
	return position;
}

/*This is the bubble sorting method from the text pg 615. It will 
sortthe values into ascending order. The first pair of values are 
compared, if the first is larger than the second they are swapped
This continues up the list until all the values are sorted.*/

void bubbleSort(int list[], size_t size)
{
	bool swapped;
	int temp = 0;

	do
	{
		swapped = false;
		for (size_t i = 0; i < (size - 1); i++)
		{
			if (list[i] > list[i + 1])
			{
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				swapped = true;
			}
		}
	} while (swapped);
}

/*Implements binary search on the sorted text files created in
the bubble sorting method if they are named test1.txt, 
test2.txt, test3.txt, and test4.txt.  Uses the algorithm 
described in pg 10 of the Searching ppt. */

int binarySearch(const int list[], size_t size, int searchTerm)
{
	int low = 0;
	int high = size - 1;

	while (low <= high)
	{
		int middle = (low + high) / 2;
		int diff = list[middle] - searchTerm;
		if (diff == 0)
		{
			return middle;
		}
		else if (diff < 0)
		{
			low = middle + 1;
		}
		else
		{
			high = middle - 1;
		}
	}

	return -1;
}
