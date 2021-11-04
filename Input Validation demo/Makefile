OBJECTS = main.o input_validation.o
CC=g++
CFLAGS=-c
CPP11=-std=c++0x

demo: $(OBJECTS)
	$(CC) $(OBJECTS) -o demo

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

input_validation.o: input_validation.cpp input_validation.hpp
	$(CC) $(CFLAGS) input_validation.cpp

clean:
	rm *.o demo
