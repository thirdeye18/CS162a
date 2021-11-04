
output: main.o Board.o Ant.o Menu.o InputValidation.o
	g++ -std=c++0x main.o Board.o Ant.o Menu.o InputValidation.o -o output
	
main.o: main.cpp
	g++ -std=c++0x -c main.cpp
	
board.o: Board.cpp Board.hpp
	g++ -c Board.cpp

ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp
	
Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp
	
InputValidation.o: InputValidation.cpp InputValidation.hpp
	g++ -std=c++0x -c InputValidation.cpp
	
clean:
	rm *.o output -f
