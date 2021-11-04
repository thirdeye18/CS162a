/*********************************************************************
** Program name: Lab 9
** Filename: PalindromeStack.hpp
** Author: Justin Hammel
** Date: 6/4/2017
** Description: Implementation for the PalindromeStack class.
*********************************************************************/

#ifndef PALINDROME_STACK_HPP
#define PALINDROME_STACK_HPP

#include <string>
#include <stack>
#include <iostream>

using std::string;
using std::stack;
using std::cout;
using std::endl;

class PalindromeStack
{
private:
	string palindromeString;

	stack <char> palindrome;
	stack <char> printStack;

public:
	PalindromeStack();
	~PalindromeStack();

	void add2Stack(string userStringIn);
	void add2String();
	void printPalindromeString();
	void printPalindromeStack();
};

#endif // !PALINDROME_STACK_HPP