/*********************************************************************
** Program name: Lab3
** Filename: Game.cpp
** Author: Justin Hammel
** Date: 4/24/2017
** Description: This is the Game class file that controls the game of
**				dice war between two players.
*********************************************************************/

#include "Game.hpp"

Game::Game()
{
	setRounds(0);
	player1Score = 0;
	player2Score = 0;
}

Game::Game(int rounds)
{
	setRounds(rounds);
	player1Score = 0;
	player2Score = 0;
}

Game::~Game()
{
}

void Game::setRounds(int rounds)
{
	this->rounds = rounds;
}

int Game::getRounds() const
{
	return this->rounds;
}

int Game::getPlayer1Score() const
{
	return this->player1Score;
}

int Game::getPlayer2Score() const
{
	return this->player2Score;
}

void Game::play(const vector<shared_ptr<Die>> &gameDie, const WhichLoaded &thisGame)
{
	cout << thisGame << endl;

	for (int i = 1; i <= rounds; i++)
	{
		int d1Result = 0;
		int d2Result = 0;
		if (thisGame == P1LOADED)
		{
			cout << "Playing with P1 loaded\n";
			d1Result = gameDie.at(2)->roll();
			d2Result = gameDie.at(1)->roll();
		}
		else if (thisGame == P2LOADED)
		{
			cout << "Playing with P2 loaded\n";
			d1Result = gameDie.at(0)->roll();
			d2Result = gameDie.at(3)->roll();
		}
		else if (thisGame == BOTH)
		{
			cout << "Playing with Both loaded\n";
			d1Result = gameDie.at(2)->roll();
			d2Result = gameDie.at(3)->roll();
		}
		else
		{
			cout << "Playing with NO loaded\n";
			d1Result = gameDie.at(0)->roll();
			d2Result = gameDie.at(1)->roll();
		}
		
		cout << "Round " << i << endl;
		cout << "Player 1, " << d1Result << endl;
		cout << "Player 2, " << d2Result << endl;
		this->tallyScore(d1Result, d2Result);
		cout << getPlayer1Score() << endl;
		cout << getPlayer2Score() << endl;
	}
}

void Game::tallyScore(int results1, int results2)
{
	if (results1 > results2)
	{
		player1Score += 1;
	}
	else if (results1 < results2)
	{
		player2Score += 1;
	}
}
