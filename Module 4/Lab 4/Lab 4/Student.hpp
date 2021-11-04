/*********************************************************************
** Program name: Lab4
** Filename: Student.hpp
** Author: Justin Hammel
** Date: 5/1/2017
** Description: This is the implementation file for my Student
**				class.
*********************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>

#include "People.hpp"

using std::cout;

class Student : public People
{
private:
	float gpa;

public:
	Student();
	Student(const string&, const int&);
	~Student();

	virtual float getInfo();

	virtual void doWork(int);
	void assignGpa();
};

#endif