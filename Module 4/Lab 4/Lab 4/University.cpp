/*********************************************************************
** Program name: Lab4
** Filename: University.cpp
** Author: Justin Hammel
** Date: 5/1/2017
** Description: Contains all the functions for the University class.
**				There are getters for the necessary data members. A 
**				default constructor sets the name to " " and zeros 
**				out the other data members.  There is another 
**				constructor that accepts values for the parameters.
**				There are functions to add buildings and people to 
**				the appropriate arrays to store them as pointers.
**				All the objects that are stored in the arrays can
**				also be preinted out as lists.
*********************************************************************/

#include "University.hpp"
#include "Student.hpp"
#include "Instructor.hpp"

/*Constructors*/

University::University()
{
	uniName = " ";
	buildingCount = 0;
	peopleCount = 0;
}

University::University(string uName, int bCount, int pCount)
{
	uniName = uName;
	buildingCount = bCount;
	peopleCount = pCount;
}

/*Destructor*/

University::~University()
{
}

/*Getters for private values*/

int University::getPeopleCount()
{
	return peopleCount;
}

People** University::getStoredPeople()
{
	return storedPeople;
}

/*Prints the building list for the university object.*/

void University::uniPrint()
{
	cout << uniName << " building listing\n";
	for (int i = 0; i < buildingCount; i++)
	{
		cout << i + 1 << ". " << storedBuildings[i].getBuildName() << endl;
		cout << "   " << storedBuildings[i].getSize() << " sqft" << endl;
		cout << "   " << storedBuildings[i].getAddress() << endl;
	}
}

/*Prints the people listing for the university object.*/

void University::peoplePrint()
{
	cout << uniName << " listing of people\n";
	for (int i = 0; i < peopleCount; i++)
	{
		cout << i + 1 << ". " << storedPeople[i]->getName() << endl;
		cout << "Age: " << storedPeople[i]->getAge() << endl;
		if (storedPeople[i]->getPtype() == STUDENT)
		{
			cout << setprecision(2) << fixed << showpoint;
			cout << "GPA: " << storedPeople[i]->getInfo() << endl;
		}
		else if (storedPeople[i]->getPtype() == INSTRUCTOR)
		{
			cout << setprecision(2) << fixed << showpoint;
			cout << "Rating: " << storedPeople[i]->getInfo() << endl;
		}
	}
}

/*Prints the names of the people for the university object.  This is used for
  generating the menu to assign work hours to a person*/

void University::namePrint()
{
	cout << uniName << " work assignment\n";
	for (int i = 0; i < peopleCount; i++)
	{
		cout << i + 1 << ". " << storedPeople[i]->getName() << endl;
	}
}

/*Function adds two building objects to the storedbuilding
array of pointers.  Currently the information for all the buildings are
hard coded in.*/

void University::addBuildings()
{
	storedBuildings = new Buildings [buildingCount];
	//Adding first building	
	string tName, tAddy;
	int tSize = 0;
	tName = tAddy = " ";
	tName = "Adams Hall";
	tSize = 11168;
	tAddy = "606 SW 15TH ST CORVALLIS, OR 97331";
	Buildings* addPtr;
	addPtr = new Buildings(tName, tSize, tAddy);
	storedBuildings[0] = *addPtr;
	
	delete addPtr;
	addPtr = NULL;

	//Adding second building
	tSize = 0;
	tName = tAddy = " ";
	tName = "Beef Pole Barn";
	tSize = 1080;
	tAddy = "3550 CAMPUS WAY CORVALLIS, OR 97330";
	addPtr = new Buildings(tName, tSize, tAddy);
	storedBuildings[1] = *addPtr;

	delete addPtr;
	addPtr = NULL;

	/* I was trying to set up the program to read
	   from a text file to load the array with 
	   building objects, moved on due to time constraints
	//setup objects to read text file
	string addBuild;
	string tName, tSize, tAddy;
	int iSize = 0;
	fstream buildFile;
	Buildings* addPtr;

	//open text file
	buildFile.open("BuildingList.txt", ios::in);

	//Verify file exists
	if (!buildFile)
	{
		cout << "Unable to find BuildingList.txt\n";
	}

	//start reading with first line of file
	getline(buildFile, tName, '$');
	getline(buildFile, tSize, '#');
	//convert read file string to int
	iSize = stringToInt(tSize);
	getline(buildFile, tAddy);

	//testing reading txt file
	cout << tName << endl;
	cout << tSize << endl;
	cout << iSize << endl;
	cout << tAddy << endl;
	addPtr = new Buildings(tName, iSize, tAddy);
	storedBuildings[0] = addPtr;
	
	while (!buildFile.fail())
	{
		int count = 1;
		//while successful push string to array
		//then read next line
		getline(buildFile, tName, '$');
		getline(buildFile, tSize, '#');
		iSize = stringToInt(tSize);
		getline(buildFile, tAddy);
		addPtr = new Buildings(tName, iSize, tAddy);
		storedBuildings[count] = addPtr;
	}

	//close text file
	buildFile.close();
	delete addPtr;*/
}

/*Function adds an instructor and a student object to the storedPeople
  array of pointers.  Currently the information for all the people are 
  hard coded in.*/

void University::addPeople()
{
	storedPeople = new People* [peopleCount];
	//Adding people 
	string pName = " ";
	int pAge = 0;
	pName = "John Doe";
	pAge = 30;
	storedPeople[0] = new Student(pName, pAge);


	pName = " ";
	pAge = 0;
	pName = "John Doe2";
	pAge = 31;
	storedPeople[1] = new Instructor(pName, pAge);
}
