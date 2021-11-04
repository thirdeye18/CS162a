/*********************************************************************
** Program name: Final Project
** Filename: Timer.hpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the implementation file for the Timer class.
*********************************************************************/

#ifndef TIMER_HPP
#define TIMER_HPP

//determining which system to use wait timer libraries for
#ifdef LINUX
#include <unistd.h>
#endif
#ifdef WINDOWS
#include <windows.h>
#endif

#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

class Timer
{
private:
	const double STOP_TIME = 20.0;
	double elapsedSeconds;
	double thirtyPrint;
	time_t start;
	time_t check;

public:
	Timer();
	~Timer();

	double getElapsedSeconds();

	bool pollTimer(bool);
	void sleeper(int sleepDelay);
	void printTimer();
};

#endif // !TIMER_HPP



