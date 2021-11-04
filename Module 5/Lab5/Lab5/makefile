
output: main.o Menu.o InputValidation.o reverseString.o sumArray.o triNumber.o
	g++ -std=c++0x main.o Menu.o InputValidation.o reverseString.o sumArray.o triNumber.o -o output
	
main.o: main.cpp
	g++ -std=c++0x -c main.cpp
	
Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++0x -c Menu.cpp
	
InputValidation.o: InputValidation.cpp InputValidation.hpp
	g++ -std=c++0x -c InputValidation.cpp
	
reverseString.o: reverseString.cpp
	g++ -std=c++0x -c reverseString.cpp

sumArray.o: sumArray.cpp
	g++ -std=c++0x -c sumArray.cpp
	
triNumber.o: triNumber.cpp
	g++ -std=c++0x -c triNumber.cpp
	
clean:
	rm *.o output -f
