/*********************************************************************
** Program name: Lab3
** Filename: Game.hpp
** Author: Justin Hammel
** Date: 4/24/2017
** Description: This is the implementation file for my Game
**				class.
*********************************************************************/
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include <memory>
#include <vector>

#include "Die.hpp"
#include "LoadedDie.hpp"

using std::shared_ptr;
using std::vector;

enum PlayResults {PLAYER_1, PLAYER_2, DRAW};
enum WhichLoaded {P1LOADED, P2LOADED, BOTH, NONE};

class Game
{
private:
	vector<shared_ptr<Die>> gameDice;
	int player1Score;
	int player2Score;
	int rounds;

public:
	Game();
	Game(int rounds);
	~Game();

	void setRounds(int rounds);
	int getRounds() const;
	int getPlayer1Score() const;
	int getPlayer2Score() const;

	void play(const vector<shared_ptr<Die>> &gameDie, const WhichLoaded &thisGame);
	void tallyScore(int results1, int results2);
};

#endif