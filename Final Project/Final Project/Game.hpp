/*********************************************************************
** Program name: Final Project
** Filename: Game.hpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the implementation file for the Game class.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Timer.hpp"
#include "Board.hpp"
#include "InputValidation.hpp"
#include "Menu.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "Space.hpp"

enum Difficulty {EASY = 1, MEDIUM = 2, HARD = 3};

class Game
{
private:
	int players;
	bool gameOver;
	int difficulty;
	int gemCount;

	Menu* playerMenu = nullptr;
	Timer* currentTimer = nullptr;
	Board* currentBoard = nullptr;
	Player player1;

public:
	Game();
	Game(int, int);
	~Game();

	void playGame();
	void processInput();
	void render();
};

#endif