/*********************************************************************
** Program name: Lab4
** Filename: Instructor.cpp
** Author: Justin Hammel
** Date: 5/1/2017
** Description:
*********************************************************************/

#include "Instructor.hpp"

/*Constructors*/

Instructor::Instructor() : People()
{
	rating = 0.0;
}

Instructor::Instructor(const string& iName, const int& iAge) : People(iName, iAge, INSTRUCTOR)
{
	this->assignRating();
}

/*Destructor*/

Instructor::~Instructor()
{
}

float Instructor::getInfo()
{
	return rating;
}

void Instructor::doWork(int x)
{
	int hour = (rand() % (x + 1));
	cout << "Instructor " << this->getName() << " graded papers for ";
	cout << hour << " hours.\n";
}

void Instructor::assignRating()
{
	float hiScore = 5.0;
	rating = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / hiScore));
}
