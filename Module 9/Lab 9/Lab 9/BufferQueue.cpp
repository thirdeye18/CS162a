/*********************************************************************
** Program name: Lab 9
** Filename: BufferQueue.cpp
** Author: Justin Hammel
** Date: 6/4/2017
** Description: This is my BufferQueue class that simulates a buffer
**				with randomly generated numbers using the STL deque
**				container.
*********************************************************************/

#include "BufferQueue.hpp"

/*Constructors*/

BufferQueue::BufferQueue()
{
	rounds = 0;
	keepPercent = 0;
	discardPercent = 0;
}

BufferQueue::BufferQueue(int roundsIn, int keepPercentIn, int discardPercentIn)
{
	rounds = roundsIn;
	keepPercent = keepPercentIn;
	discardPercent = discardPercentIn;
}

/*Destructor*/

BufferQueue::~BufferQueue()
{
	
}

/*Runs the buffer simulation.  Calls the random number functions 
to fill the number, keep, and discard members. Prints the contents
of the buffer after each round. Uses calcAvgSize method to determine
and print the average size of the buffer.*/

void BufferQueue::runBufferSim()
{
	for (int i = 1; i <= rounds; i++)
	{
		cout << "Round " << i << endl;
		
		//generating new number
		number = generateNumber();
		cout << "Random number between 1 and 1000 generated: ";
		cout << number << endl;

		//deciding whether to keep generated number
		keepNumber();

		//deciding whether to remove number from buffer
		removeBuffer();

		cout << endl;

		printBuffer();

		calcAvgSize(i);
	}
}

/*Deciding whether to keep randomly generated number from first 
step of runBufferSim.*/

void BufferQueue::keepNumber()
{
	//generating percentage
	keep = generatePercent();
	cout << "Keep percentage generated: ";
	cout << keep << endl;

	//comparing percentage to user determined value to keep
	if (keep <= keepPercent)
	{
		buffQueue.push_back(number);
	}
}

/*Deciding whether to remove a value from the front of the buffer.*/

void BufferQueue::removeBuffer()
{
	//generating percentage
	discard = generatePercent();
	cout << "Discard percentage generated: ";
	cout << discard << endl;

	//comparing percentage to user determined value to discard
	if (discard <= discardPercent && !buffQueue.empty())
	{
		buffQueue.pop_front();
	}
}

/*Prints the contents of the buffer to the screen. Prints 20 values 
per line.*/

void BufferQueue::printBuffer()
{
	cout << "Contents of the buffer are: \n";
	for (size_t i = 0; i < buffQueue.size(); i++)
	{
		cout << buffQueue[i] << " ";
		if ((i + 1) % 20 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

/*Method to calculate the average size of the buffer each round.*/

void BufferQueue::calcAvgSize(int currentRound)
{
	//for first round average length will be whatever current is
	if (currentRound = 1)
	{
		avgLengthLast = avgLengthCurrent = currentSize = lastSize = 
			buffQueue.size();
	}
	else
	{
		//Moving current values to last values for saving
		lastSize = currentSize;
		avgLengthLast = avgLengthCurrent;

		//generating new current and average size values
		currentSize = buffQueue.size();
		avgLengthCurrent = (avgLengthLast * (currentRound - 1) + 
			currentSize) / currentRound;

	}

	cout << "Queue average length = " << avgLengthCurrent << endl;
	cout << endl;
}

/*Generates random int from 1-1000 for the queue.*/

int BufferQueue::generateNumber()
{
	return rand() % 1000 + 1;
}

/*Generates random int from 1-100 acting as a percentage value.*/

int BufferQueue::generatePercent()
{
	return rand() % 100 + 1;
}
