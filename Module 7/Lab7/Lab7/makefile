CXX = g++
CXXFLAGS = -std=c++0x

OBJS = main.o Menu.o InputValidation.o Queue.o

SRCS = main.cpp Menu.cpp InputValidation.cpp Queue.cpp

INCLUDES = Menu.hpp InputValidation.hpp Queue.hpp

output: ${OBJS} ${INCLUDES}
	${CXX} ${CXXFLAGS} ${OBJS} -o output

${OBS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o output -f