
output: main.o Menu.o InputValidation.o Item.o List.o
	g++ -std=c++0x main.o Menu.o InputValidation.o Item.o List.o -o output
	
main.o: main.cpp
	g++ -std=c++0x -c main.cpp
	
Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++0x -c Menu.cpp
	
InputValidation.o: InputValidation.cpp InputValidation.hpp
	g++ -std=c++0x -c InputValidation.cpp
	
Item.o: Item.cpp Item.hpp
	g++ -std=c++0x -c Item.cpp

List.o: List.cpp List.hpp
	g++ -std=c++0x -c List.cpp
	
clean:
	rm *.o output -f
