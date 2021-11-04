/*********************************************************************
** Program name: Lab 8
** Filename: main.cpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: Function definitions for the search and sort methods 
**				from Lab 8.
*********************************************************************/

#ifndef SEARCH_SORT_HPP
#define SEARCH_SORT_HPP

#include <iostream>

int linearSearch(const int list[], size_t size, int searchTerm);

void bubbleSort(int list[], size_t size);

int binarySearch(const int list[], size_t size, int searchTerm);

#endif // !SEARCH_SORT_HPP
