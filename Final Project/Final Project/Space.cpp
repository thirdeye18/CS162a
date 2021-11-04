/*********************************************************************
** Program name: Final Project
** Filename: Space.cpp
** Author: Justin Hammel
** Date: 6/14/2017
** Description: This is the Space base class for my final project.
**				The directional pointers will point to new spaces as
**				they are created.  From the beginning they start as
**				nullptrs.  Space coordinates will be assigned by the 
**				Board class for storing them in the map.
*********************************************************************/

#include "Space.hpp"

/*Constructors*/

Space::Space()
{
	travel1 = randIcon(2);
	travel2 = randIcon(2);
	for (size_t i = 0; i < 4; i++)
	{
		exits[i] = nullptr;
	}
}

/*Destructor*/

Space::~Space()
{
}

/*Function generates random icon for space parameters. Passed integer
represents what available icons the returned char should be. Will
be passed a 2 when for a travel or treasure parameter.  3 is passed
for gem activation.*/

char Space::randIcon(int choices)
{
	int randNum = 0;
	randNum = rand() % choices + 1;
	if (randNum == 1)
	{
		return 'T';
	}
	if (randNum == 2)
	{
		return 'K';
	}
	if (randNum == 3)
	{
		return 'A';
	}
}

/*Fills layout array with characters from the space layout text 
files.  Files are filled with ascii values for the required 
required characters.*/

void Space::fillSpace(string spaceLayoutFile)
{
	//setup objects to read text file
	ifstream spaceFile;
	string spaceBlock = "";

	//open text file
	spaceFile.open(spaceLayoutFile, ios::binary);

	//Verify file exists
	if (!spaceFile)
	{
		cout << "Unable to find " << spaceLayoutFile << " \n";
	}

	getline(spaceFile, spaceBlock);
	while (spaceFile)
	{
		//while successful read char to array
		//then read next line
		for (size_t i = 0; i < 7; i++)
		{
			layout[i] = spaceBlock;
			getline(spaceFile, spaceBlock);
		}
	}

	//close text file
	spaceFile.close();

	//Inserting space travel icons
	string line2 = layout[1];
	line2[1] = travel1;
	line2[2] = travel2;
	layout[1] = line2;
}

/*Makes openings in the space layout to show where the player entered
from.  EnterDirection is based on where the player exited the last
room.*/

void Space::spaceEntrance(Direction in)
{
	if (in == UP)
	{
		string line6 = layout[6];
		line6[3] = ' ';
		layout[6] = line6;
	}
	else if (in == DOWN)
	{
		string line0 = layout[0];
		line0[3] = ' ';
		layout[0] = line0;
	}
	if (in == LEFT)
	{
		string line3 = layout[3];
		line3[6] = ' ';
		layout[3] = line3;
	}
	if (in == RIGHT)
	{
		string line3 = layout[3];
		line3[0] = ' ';
		layout[3] = line3;
	}
}

/*Connecting and re-assigning pointers for spaces.  First checks if
the exits from the space and to new space are nullptr.  Returns false
if the space is already connected otherwise assigns the exits to the 
pointers and returns true.*/

bool Space::makePaths(Direction exit, Space * s, Direction to)
{
	if (exits[exit] != nullptr || exits[to] != nullptr)
	{
		return false;
	}
	exits[exit] = s;
	s->exits[to] = this;
}

/*Randomly determines what type of space will be made. Int returned
corresponds to the type of space that will be made. 1 is the exit,
2-5 are the gem rooms (only 4 total), all other rolls yield plain
room.  Plain room has 50% chance of containing treasure. Exit room
is not available unitl 5 spaces have been generated, controlled by
the spaceCount variable. The tileCount variable decreases the max
random value (as spaces created tiles available decrease by 1).*/

//int Space::spacePicker(Board* layout)
//{
//	int randNum = 0;
//
//	randNum = rand() % (layout->getTotalTiles() + 1);
//
//	if ((layout->getSpaceCount()) < 5)
//	{
//		//2-5 creating gem room
//		if ((randNum >= 2 || randNum <= 5) && (layout->getGemRooms()) > 0)
//		{
//			return 2;
//		}
//		//Standard room in all other cases
//		else
//		{
//			//50% chance to have treasure room
//			randNum = rand() % 2;
//			if (randNum)
//			{
//				return 3;
//			}
//			else
//			{
//				return 4;
//			}
//		}
//	}
//	else
//	{
//		//1 generates exit room
//		if (randNum == 1)
//		{
//			return 1;
//		}
//		//2-5 creating gem room
//		else if ((randNum >= 2 || randNum <= 5) && (layout->getGemRooms()) > 0)
//		{
//			return 2;
//		}
//		//Standard room in all other cases
//		else
//		{
//			//50% chance to have treasure room
//			randNum = rand() % 2;
//			if (randNum)
//			{
//				return 3;
//			}
//			else
//			{
//				return 4;
//			}
//		}
//	}
//}

/*generates spaces to pass back to the Board class. Int types come
from the spacePicker method.*/

//Space* Space::generateSpace(Board* layout, Direction in)
//{
//	//determine space type to be made
//	int spaceType = spacePicker(layout);
//
//	//Creates exit space
//	if (spaceType == 1)
//	{
//		return new ExitSpace(in);
//	}
//
//	//Creates Gem Space
//	else if (spaceType == 2)
//	{
//		return new GemSpace;
//	}
//
//	//Creates Standard Space
//	else if (spaceType == 3)
//	{
//		return new StandardSpace;
//	}
//
//	//Creates Treasure Space
//	else
//	{
//		return new TreasureSpace;
//	}
//}

/*Steps through the layout array printing the characters to the
screen.*/

void Space::printSpace()
{
	for (size_t i = 0; i < 7; i++)
	{
		for (size_t j = 0; j < 7; j++)
		{
			cout << layout[i][j] << " ";
		}
		cout << endl;
	}
}

/*Move between spaces.*/

void Space::travel()
{
}

