CXX = g++
CXXFLAGS = -std=c++0x

OBJS = main.o Menu.o InputValidation.o SearchSort.o

SRCS = main.cpp Menu.cpp InputValidation.cpp SearchSort.cpp

INCLUDES = Menu.hpp InputValidation.hpp SearchSort.hpp

output: ${OBJS} ${INCLUDES}
	${CXX} ${CXXFLAGS} ${OBJS} -o output

${OBS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o output -f