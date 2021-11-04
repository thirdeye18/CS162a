/*********************************************************************
** Program name: Lab3
** Filename: LoadedDie.cpp
** Author: Justin Hammel
** Date: 4/24/2017
** Description: This is the Loaded Die class file which inherits from 
**				the Die class.
*********************************************************************/

#include "LoadedDie.hpp"

LoadedDie::LoadedDie() : Die()
{

}

LoadedDie::LoadedDie(const int& N) : Die(this->N)
{

}

LoadedDie::~LoadedDie()
{
}

/*This function returns the randome loaded roll value. Generates a 
  random double between 1 and 0 to represent a probability.  The 
  probability is then compared to the expected probability of 
  rolling a specific number.  The probabilities are weighted, so
  it is twice as likely to roll a number that is higher than the
  expected average roll.  Uses formulas and concepts pulled from 
  the Wikipedia article linked in Piazza thread.
  https://en.wikipedia.org/wiki/Expected_value
  The random function needs to be seeded in the main.*/

int LoadedDie::roll() const
{
	cout << "Using Loaded Roll\n";
	double randProb = 0.0;
	double expected = 0.0;
	//generates random probability
	randProb = ((double)rand() / (RAND_MAX)) + 1;

	//calculate the expected value = x1*p1 + x2*p2...xN*pN
	for (int i = 1; i <= this->getSides(); i++)
	{
		expected += i * (1 / this->getSides());
	}
	/*will use truncated expected value to generate new probability 
	  with weight towards values above the expected value*/
	int expVar = 0;
	expVar = expected;
	int biasReturn = 0;
	//calculate new probabilities for Hi vs Low numbers
	double loopProbHi = 0.0;
	loopProbHi = 1 / (this->getSides() + expVar);
	double loopProbLo = 0.0;
	loopProbLo = 2 / (this->getSides() + expVar);
	//keeping track of total probability, sum of all probs
	double totalProb = 0.0;

	//check if random generated earlier < expected value probs
	for (int i = 1; i <= (this->getSides()) / 2; i++)
	{
		cout << i;
		totalProb += loopProbLo;
		if (randProb < totalProb)
		{
			return i;
		}
	}
	for (int i = (this->getSides() + 1) / 2; 
		i <= this->getSides(); i++)
	{
		totalProb += loopProbHi;
		if (randProb < totalProb)
		{
			return i;
		}
	}
	//return -1;
}
