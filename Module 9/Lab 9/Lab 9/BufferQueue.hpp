/*********************************************************************
** Program name: Lab 9
** Filename: BufferQueue.hpp
** Author: Justin Hammel
** Date: 6/4/2017
** Description: Implementation for the BufferQueue class.
*********************************************************************/

#ifndef BUFFER_QUEUE_HPP
#define BUFFER_QUEUE_HPP

#include <deque>
#include <iostream>

using std::string;
using std::deque;
using std::cout;
using std::endl;

class BufferQueue
{
private:
	int rounds;
	int keepPercent;
	int discardPercent;

	//members to hold randon values for each round
	int number;
	int keep;
	int discard;

	//members for average queue length calc
	int avgLengthLast;
	int avgLengthCurrent;
	int currentSize;
	int lastSize;

	deque<int> buffQueue;

public:
	BufferQueue();
	BufferQueue(int roundsIn, int keepPercentIn, int discardPercentIn);
	~BufferQueue();

	void runBufferSim();
	void keepNumber();
	void removeBuffer();
	void printBuffer();
	void calcAvgSize(int currentRound);

	int generateNumber();
	int generatePercent();
};

#endif // !BUFFER_QUEUE_HPP