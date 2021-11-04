/*********************************************************************
** Program name: Lab3
** Filename: LoadedDie.hpp
** Author: Justin Hammel
** Date: 4/24/2017
** Description: This is the implementation file for my LoadedDie 
**				class.
*********************************************************************/
#ifndef LOADED_DIE_HPP
#define LOADED_DIE_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Die.hpp"

using std::cout;
using std::endl;

class LoadedDie : public Die
{
private:

public:
	LoadedDie();
	LoadedDie(const int& N);
	~LoadedDie();

	virtual int roll() const;
};


#endif