/*********************************************************************
** Program name: Lab3
** Filename: Die.hpp
** Author: Justin Hammel
** Date: 4/24/2017
** Description: This is the implementation file for my Die class.
*********************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "InputValidation.hpp"

using std::cout;
using std::string;
using std::cin;
using std::endl;

class Die
{
protected:
	int N;
	bool loaded;

public:
	Die();
	Die(int);
	~Die();

	void setSides(const int& N);
	void setLoaded(const bool& loaded);

	int getSides() const;
	bool getLoaded() const;

	int inputSides();
	void makeLoaded();

	virtual int roll();
};

#endif

