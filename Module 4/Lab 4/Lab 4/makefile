
output: main.o Menu.o InputValidation.o University.o Buildings.o People.o Student.o Instructor.o
	g++ -std=c++0x main.o Menu.o InputValidation.o University.o Buildings.o People.o Student.o Instructor.o -o output
	
main.o: main.cpp
	g++ -std=c++0x -c main.cpp
	
Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++0x -c Menu.cpp
	
InputValidation.o: InputValidation.cpp InputValidation.hpp
	g++ -std=c++0x -c InputValidation.cpp
	
University.o: University.cpp University.hpp
	g++ -std=c++0x -c University.cpp

Buildings.o: Buildings.cpp Buildings.hpp
	g++ -std=c++0x -c Buildings.cpp
	
People.o: People.cpp People.hpp
	g++ -std=c++0x -c People.cpp
	
Student.o: Student.cpp Student.hpp
	g++ -std=c++0x -c Student.cpp
	
Instructor.o: Instructor.cpp Instructor.hpp
	g++ -std=c++0x -c Instructor.cpp
	
clean:
	rm *.o output -f
