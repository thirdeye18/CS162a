/*********************************************************************
** Program name: Lab 9
** Filename: PalindromeStack.cpp
** Author: Justin Hammel
** Date: 6/4/2017
** Description: This is my PalindromeStack class that returns the 
**				palindrome of a string passed using the STL stack
**				container.
*********************************************************************/

#include "PalindromeStack.hpp"


PalindromeStack::PalindromeStack()
{
}


PalindromeStack::~PalindromeStack()
{
}

/*Adding user string values to the stack. This will also add the 
original string to the palindromeString.*/

void PalindromeStack::add2Stack(string userStringIn)
{
	for (size_t i = 0; i < userStringIn.length(); i++)
	{
		palindrome.push(userStringIn[i]);
	}
	palindromeString = userStringIn;
}

/*Puts the values of the stack to the end of a string.*/

void PalindromeStack::add2String()
{

	while (!palindrome.empty())
	{
		palindromeString += palindrome.top();
		palindrome.pop();
	}
}

/*Print the palindrome string.*/

void PalindromeStack::printPalindromeString()
{
	cout << palindromeString;
}

/*Print the stack contents for testing.*/

void PalindromeStack::printPalindromeStack()
{
	while (!palindrome.empty())
	{
		cout << palindrome.top();
		printStack.push(palindrome.top());
		palindrome.pop();
	}
	cout << endl;
	while (!printStack.empty())
	{
		palindrome.push(printStack.top());
		printStack.pop();
	}
}
