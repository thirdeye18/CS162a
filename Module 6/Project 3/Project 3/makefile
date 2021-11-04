
output: main.o Menu.o InputValidation.o Dice.o Creature.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o Fight.o
	g++ -std=c++0x main.o Menu.o InputValidation.o Dice.o Creature.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o Fight.o -o output
	
main.o: main.cpp
	g++ -std=c++0x -c main.cpp
	
Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++0x -c Menu.cpp
	
InputValidation.o: InputValidation.cpp InputValidation.hpp
	g++ -std=c++0x -c InputValidation.cpp
	
Dice.o: Dice.cpp Dice.hpp
	g++ -std=c++0x -c Dice.cpp

Creature.o: Creature.cpp Creature.hpp
	g++ -std=c++0x -c Creature.cpp
	
Vampire.o: Vampire.cpp Vampire.hpp
	g++ -std=c++0x -c Vampire.cpp
	
Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -std=c++0x -c Barbarian.cpp
	
BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -std=c++0x -c BlueMen.cpp
	
Medusa.o: Medusa.cpp Medusa.hpp
	g++ -std=c++0x -c Medusa.cpp
	
HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -std=c++0x -c HarryPotter.cpp
	
Fight.o: Fight.cpp Fight.hpp
	g++ -std=c++0x -c Fight.cpp
	
clean:
	rm *.o output -f
