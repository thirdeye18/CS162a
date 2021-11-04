/*********************************************************************
** Program name: Lab4
** Filename: Student.cpp
** Author: Justin Hammel
** Date: 5/1/2017
** Description: This is the implementation file for my Student
**				class.
*********************************************************************/

#include "Student.hpp"


/*Default Constructors*/

Student::Student() : People()
{
	gpa = 0.00;
}

Student::Student(const string& sName, const int& sAge) : People(sName, sAge, STUDENT)
{
	this->assignGpa();
}

/*Default Destructor*/

Student::~Student() 
{
}

/*Function returns the float value for the students gpa*/

float Student::getInfo()
{
	return gpa;
}

/*This function assigns a random number of work hours to the student
  and then outputs the results to the screen. The function accepts an 
  int value x that goes into the rand() calculation as the max hours that
  will be returned.*/

  /*Function assigns a random ammount of work to the student and displays
    how many hours the student studied for.*/

void Student::doWork(int x)
{
	int hour = (rand() % (x + 1));
	cout << this->getName() << " did " << hour << " hours of homework\n";
}

/*This function assigns a random gpa to the student between 0.0 and hi score 
  value. Used based on method for returning a random float found at
  http://stackoverflow.com/questions/686353/c-random-float-number-generation
  */

void Student::assignGpa()
{
	float hiScore = 4.0;
	gpa = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / hiScore));
}
