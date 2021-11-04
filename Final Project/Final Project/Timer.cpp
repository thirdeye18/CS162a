/*********************************************************************
** Program name: Final Project
** Filename: Timer.cpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the Timer class for my final project that 
**				determines when the allowed time for the game has 
**				elapsed.  After allowed time up gameOver will be 
**				shifted to true.
*********************************************************************/

#include "Timer.hpp"

/*Constructor*/

Timer::Timer()
{
	elapsedSeconds = 0.0;
	thirtyPrint = 5.0;
	time(&start);
}

/*Destructor*/

Timer::~Timer()
{
}

double Timer::getElapsedSeconds()
{
	return elapsedSeconds;
}

/*Update function for the game play.  Determines if the alloted time
has passed (10 minutes).  If time is up, returns true, otherwise 
returns false.*/

bool Timer::pollTimer(bool gameState)
{
	if (!gameState)
	{
		elapsedSeconds = difftime(time(&check), start);
		if (elapsedSeconds > STOP_TIME)
		{
			return true;
		}
	}
	return false;
}

/*Sleep timer for Windows and Linux systems. Taken from 
https://stackoverflow.com/questions/10918206/cross-platform-sleep-function-for-c */

void Timer::sleeper(int sleepDelay)
{
	#ifdef LINUX
		usleep(sleepMs * 1000);   // usleep takes sleep time in us (1 millionth of a second)
	#endif
	#ifdef WINDOWS
		Sleep(sleepMs);
	#endif
}

/*Prints the elapsed time for the game to the screen.*/

void Timer::printTimer()
{
	//int outputSeconds = (int)elapsedSeconds;
	if (elapsedSeconds == thirtyPrint)
	{
		cout << "Seconds elapsed: " << elapsedSeconds << endl;
		thirtyPrint += 5.0;
	}
}
