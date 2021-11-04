/*********************************************************************
** Program name: Project 4
** Filename: Tournament.hpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: This is the implementation for the Tournament class.
*********************************************************************/

#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include "InputValidation.hpp"
#include "Menu.hpp"
#include "Fight.hpp"
#include "Creature.hpp"
#include "Dice.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "CreatureList.hpp"

enum CreatureType {VAMPIRE, BARBARIAN, BLUE_MEN, MEDUSA, HARRY_POTTER, INVALID};

class Tournament
{
private:
	int teamSize;
	int cpuScore;
	int humanScore;
	CreatureList humanQueue;
	CreatureList cpuQueue;
	CreatureList humanLoserStack;
	CreatureList CPULoserStack;
	Creature* userCreat;
	Menu* creatureMenu;

public:
	Tournament();
	Tournament(int teamSizeIn);
	~Tournament();

	CreatureType selectCreature();
	void derivedCreature(CreatureType chosenIn);
	void fillHumanQueue();
	void fillCPUQueue();
	void runTournament();
	void tallyScore(int teamNumber);
};

#endif