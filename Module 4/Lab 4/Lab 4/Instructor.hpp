/*********************************************************************
** Program name: Lab4
** Filename: Instructor.hpp
** Author: Justin Hammel
** Date: 5/1/2017
** Description: This is the implementation file for my Instructor 
**				class.
*********************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include <iostream>

#include "People.hpp"

using std::cout;

class Instructor : public People
{
private:
	float rating;

public:
	Instructor();
	Instructor(const string&, const int&);
	~Instructor();

	virtual float getInfo();

	virtual void doWork(int);
	void assignRating();
};

#endif // !INSTRUCTOR_HPP