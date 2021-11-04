/*********************************************************************
** Program name: Final Project
** Filename: Game.cpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the Game class for my final project that
**				gontrols the flow of the game.
*********************************************************************/

#include "Game.hpp"

/*Constructors*/

Game::Game()
{
	players = 0;
	difficulty = 0;
	gameOver = false;
	playerMenu = new Menu("playerMenu.txt");
}

Game::Game(int playersIn, int difficultyIn)
{
	players = playersIn;
	gameOver = false;

	//setting difficulty, adjusting Game gem count
	difficulty = difficultyIn;
	if (difficulty == EASY)
	{
		gemCount = 5;
	}
	else if (difficulty == MEDIUM)
	{
		gemCount = 15;
	}
	else
	{
		gemCount = 25;
	}

	//Game Objects
	playerMenu = new Menu("playerMenu.txt");
	currentBoard = new Board;
}

/*Destructor*/

Game::~Game()
{
	delete currentTimer;
	currentTimer = nullptr;
	delete playerMenu;
	playerMenu = nullptr;
	delete currentBoard;
	currentBoard = nullptr;
}

/*Main game flow control loop.*/

void Game::playGame()
{
	currentTimer = new Timer;

	while (!gameOver)
	{
		//render
		render();
		
		processInput();
		
		//update timer
		if (currentTimer->pollTimer(gameOver))
		{
			gameOver = true;
		}
		currentTimer->pollTimer(gameOver);
		currentTimer->printTimer();
		
		currentTimer->sleeper(16);
	}
	cout << "The game is over!\n";
}

/*Controls user input for the game.*/

void Game::processInput()
{
	//menu option variables
	const int PLAYER_OPTIONS = 4;
	int playerChoice = 0;

	playerChoice = playerMenu->userChoice(PLAYER_OPTIONS);
}

/*Controls printing the board for the game.*/

void Game::render()
{
	//printing menu
	playerMenu->printMenu();
	cout << "Please select an option from the menu.\n";

	currentBoard->printBoard();
}
