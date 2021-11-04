CXX = g++
CXXFLAGS = -std=c++0x

OBJS = main.o Menu.o InputValidation.o PalindromeStack.o BufferQueue.o

SRCS = main.cpp Menu.cpp InputValidation.cpp PalindromeStack.cpp BufferQueue.cpp

INCLUDES = Menu.hpp InputValidation.hpp PalindromeStack.hpp BufferQueue.hpp

output: ${OBJS} ${INCLUDES}
	${CXX} ${CXXFLAGS} ${OBJS} -o output

${OBS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o output -f