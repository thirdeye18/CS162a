
output: main.o readMatrix.o determinant.o
	g++ -std=c++0x main.o readMatrix.o determinant.o -o output
	
main.o: main.cpp
	g++ -std=c++0x -c main.cpp
	
readMatrix.o: readMatrix.cpp readMatrix.hpp
	g++ -std=c++0x -c readMatrix.cpp

determinant.o: determinant.cpp determinant.hpp
	g++ -std=c++0x -c determinant.cpp
	
clean:
	rm *.o output