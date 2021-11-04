
output: main.o Menu.o InputValidation.o IntList.o
	g++ -std=c++0x main.o Menu.o InputValidation.o IntList.o -o output
	
main.o: main.cpp
	g++ -std=c++0x -c main.cpp
	
Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++0x -c Menu.cpp
	
InputValidation.o: InputValidation.cpp InputValidation.hpp
	g++ -std=c++0x -c InputValidation.cpp
	
IntList.o: IntList.cpp IntList.hpp
	g++ -std=c++0x -c IntList.cpp

clean:
	rm *.o output -f
