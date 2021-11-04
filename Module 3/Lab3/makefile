
output: main.o Menu.o InputValidation.o Die.o LoadedDie.o Game.o
	g++ -std=c++0x main.o Menu.o InputValidation.o Die.o LoadedDie.o Game.o -o output
	
main.o: main.cpp
	g++ -std=c++0x -c main.cpp
	
Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++0x -c Menu.cpp
	
InputValidation.o: InputValidation.cpp InputValidation.hpp
	g++ -std=c++0x -c InputValidation.cpp
	
Die.o: Die.cpp Die.hpp
	g++ -std=c++0x -c Die.cpp

LoadedDie.o: LoadedDie.cpp LoadedDie.hpp
	g++ -std=c++0x -c LoadedDie.cpp
	
Game.o: Game.cpp Game.hpp
	g++ -std=c++0x -c Game.cpp
	
clean:
	rm *.o output -f
