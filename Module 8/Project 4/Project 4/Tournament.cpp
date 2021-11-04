/*********************************************************************
** Program name: Project 4
** Filename: Tournament.cpp
** Author: Justin Hammel
** Date: 5/29/2017
** Description: This is the implementation for the Tournament class.
*********************************************************************/

#include "Tournament.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "InputValidation.hpp"
#include "Fight.hpp"
#include "CreatureList.hpp"

/*Constructors*/

Tournament::Tournament()
{
	teamSize = 0;
	userCreat = nullptr;
}

Tournament::Tournament(int teamSizeIn)
{
	teamSize = teamSizeIn;
	userCreat = nullptr;
	creatureMenu = new Menu("CreatureMenuOptions.txt");
	humanScore = 0;
	cpuScore = 0;
}

/*Destructor*/

Tournament::~Tournament()
{
	delete creatureMenu;
	creatureMenu = nullptr;

	userCreat = nullptr;
}

/*Controls the menu for selecting the creatures being added to the 
user queues. Returns an enumerated type based on the creature type
selected.*/

CreatureType Tournament::selectCreature()
{
	int creatChoice = creatureMenu->userChoice();

	if (creatChoice == 1)//Vampire
	{
		creatureMenu->clearScreen();
		cout << "Vampire selected.\n";
		return VAMPIRE;
	}

	else if (creatChoice == 2)//Barbarian
	{
		creatureMenu->clearScreen();
		cout << "Barbarian selected.\n";
		return BARBARIAN;
	}

	else if (creatChoice == 3)//Blue Men
	{
		creatureMenu->clearScreen();
		cout << "Blue Men selected.\n";
		return BLUE_MEN;
	}

	else if (creatChoice == 4)//Medusa
	{
		creatureMenu->clearScreen();
		cout << "Medusa selected.\n";
		return MEDUSA;
	}

	else if (creatChoice == 5)//Harry Potter
	{
		creatureMenu->clearScreen();
		cout << "Harry Potter selected.\n";
		return HARRY_POTTER;
	}
	
	else//invalid menu option
	{
		cout << "Invalid menu choice! Please try again\n";
		creatureMenu->clearScreen();
		return INVALID;
	}
}

/*Creates derived creature based on chosen enum of CreatureType*/

void Tournament::derivedCreature(CreatureType chosenIn)
{
	if (chosenIn == VAMPIRE)
	{
		userCreat = new Vampire();
	}
	else if (chosenIn == BARBARIAN)
	{
		userCreat = new Barbarian();
	}
	else if (chosenIn == BLUE_MEN)
	{
		userCreat = new BlueMen();
	}
	else if (chosenIn == MEDUSA)
	{
		userCreat = new Medusa();
	}
	else if (chosenIn == HARRY_POTTER)
	{
		userCreat = new HarryPotter();
	}
}

/*Method for filling the human team list.  selectCreature method is 
used to get the pointer for the creature being added.*/

void Tournament::fillHumanQueue()
{
	for (int i = 1; i <= teamSize; i++)
	{
		creatureMenu->printMenu();
		CreatureType chosen = INVALID;
		cout << "Please select a creature for the human team\n";
		chosen = selectCreature();
		while (chosen == INVALID)
		{
			cout << "Please chose a valid creature type from the previous ";
			cout << "menu!\n";
			cout << "Chose the integer value next to the creature.\n";
			chosen = selectCreature();
		}
		
		//assigning new Creature to userCreat
		derivedCreature(chosen);

		//adding creature pointer to the back of the queue
		humanQueue.addEnd(userCreat);
		userCreat = nullptr;
		cout << teamSize - i << " choices remaning for the human team.\n";
	}

	humanQueue.display();
}

/*Method for filling the CPU team list.  selectCreature method is
used to get the pointer for the creature being added.*/

void Tournament::fillCPUQueue()
{
	for (int i = 1; i <= teamSize; i++)
	{
		creatureMenu->printMenu();
		CreatureType chosen = INVALID;
		cout << "Please select a creature for the CPU team\n";
		chosen = selectCreature();
		while (chosen == INVALID)
		{
			cout << "Please chose a valid creature type from the previous ";
			cout << "menu!\n";
			cout << "Chose the integer value next to the creature.\n";
			chosen = selectCreature();
		}

		//assigning new Creature to userCreat
		derivedCreature(chosen);

		//adding creature pointer to the back of the queue
		cpuQueue.addEnd(userCreat);
		userCreat = nullptr;
		cout << teamSize - i << " choices remaning for CPU team.\n";
	}
	cpuQueue.display();
}

/*Method for cycling throught the list creatures and running them 
through the fight method.*/

void Tournament::runTournament()
{
	//pointer to hold the 2 creatures fighting at a given time
	Creature* creature1;
	Creature* creature2;
	creature1 = nullptr;
	creature2 = nullptr;

	//creating fight object for combat
	Fight* currentFight;
	currentFight = nullptr;

	creature1 = humanQueue.removeFront();
	creature2 = cpuQueue.removeFront();

	while (creature1 != nullptr && creature2 != nullptr)
	{
		cout << "Preparing for battle!\n";
		cout << endl;

		currentFight = new Fight(creature1, creature2);

		int round = 1;
		while (creature1->getStr() > 0 && creature2->getStr() > 0)
		{
			currentFight->combat(round);
		}

		//display the fight winner
		if (creature1->getStr() > 0)
		{
			cout << "Human creature ";
			creature1->printName();
			cout << " the ";
			creature1->printType();
			cout << " wins!\n";
			cout << endl;

			//moving winning creature to queue and loser to stack
			CPULoserStack.addFront(creature2);
			creature1->heal();
			humanQueue.addEnd(creature1);
			tallyScore(1);
		}
		else
		{
			cout << "CPU creature ";
			creature2->printName();
			cout << " the ";
			creature2->printType();
			cout << " wins!\n";
			cout << endl;

			//moving winning creature to queue and loser to stack
			humanLoserStack.addFront(creature1);
			creature2->heal();
			cpuQueue.addEnd(creature2);
			tallyScore(2);
		}

		//setting up for the next round of combat
		//delete creature1;
		//delete creature2;
		creature1 = nullptr;
		creature2 = nullptr;

		creature1 = humanQueue.removeFront();
		creature2 = cpuQueue.removeFront();
	}

	//outputting loosing creature lists
	cout << "The following creatures were defeated in battle.\n";
	cout << "Human team:\n";
	humanLoserStack.display();
	cout << endl;

	cout << "CPU team:\n";
	CPULoserStack.display();
	cout << endl;

	if (humanScore > cpuScore)
	{
		cout << "The humans won the tournament!\n";
		cout << "Final score Humans: " << humanScore;
		cout << " CPU: " << cpuScore << endl;
		cout << endl;
	}
	else
	{
		cout << "The CPU won the tournament!\n";
		cout << "Final score Humans: " << humanScore;
		cout << " CPU: " << cpuScore << endl;
		cout << endl;
	}

	//cleaning up after the tournament
	delete creature1;
	delete creature2;
	creature1 = nullptr;
	creature2 = nullptr;
	delete currentFight;
	currentFight = nullptr;
}

/*Method tallies up the tournament score. Each combat win gives 2
points to the winning team for that round.*/

void Tournament::tallyScore(int teamNumber)
{
	if (teamNumber == 1)
	{
		humanScore += 2;
	}
	else if (teamNumber == 2)
	{
		cpuScore += 2;
	}
}

