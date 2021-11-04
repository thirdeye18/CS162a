/*********************************************************************
** Program name: Project3
** Filename: Fight.cpp
** Author: Justin Hammel
** Date: 5/15/2017
** Description: This the Fight class that controls combat between the 
**				two Creature derived objects.
********************************************************************/

#include "Fight.hpp"

Fight::Fight()
{
	turn = 0;
	creatArry[0] = NULL;
	creatArry[1] = NULL;
}

Fight::Fight(Creature* creat1In, Creature* creat2In)
{
	randomStart();
	creatArry[0] = creat1In;
	creatArry[1] = creat2In;
}


Fight::~Fight()
{
}

/*Function that randomly selects one of the creatures to attack 
  first.  Uses the srand() seed from the main function.*/

void Fight::randomStart()
{
	turn = rand() % 2;
}

/*This function controls the flow of combat.  It will call the 
dice rolling function for the two creatures and swith turns between 
the two.  This function, along with the defense and damage functions
in the Creature, or derived classes handle printing the combat stats
for each round.*/

void Fight::combat(int& roundIn)
{
	//display round and creature attacking info
	cout << "Round: " << roundIn << endl;
	creatArry[turn]->printName();
	cout << " creature # " << turn + 1;
	cout << " attacks!\n";

	//generate atk and display
	int comAtk = creatArry[turn]->attack();
	//cout << "Attack: " << comAtk << endl;

	//switching turn
	if (!turn)
	{
		turn = 1;
	}
	else
	{
		turn = 0;
	}

	//generate def and display armour value
	int comDef = creatArry[turn]->defense(comAtk);
	cout << "Armour: " << creatArry[turn]->getArm() << endl;
	
	//apply and display damage
	creatArry[turn]->damage(comDef);

	//display current strength
	cout << "Creature " << turn + 1 << ", ";
	creatArry[turn]->printName();
	cout << " current strength: " << creatArry[turn]->getStr() << endl;
	cout << endl;

	//increment round counter for display
	roundIn += 1;
}
