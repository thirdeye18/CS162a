CXX = g++
CXXFLAGS = -std=c++0x

OBJS = main.o Menu.o InputValidation.o Dice.o Game.o Board.o Space.o ExitSpace.o GemSpace.o StandardSpace.o StartSpace.o TreasureSpace.o Timer.o Player.o

SRCS = main.cpp Menu.cpp InputValidation.cpp Dice.cpp Game.cpp Board.cpp Space.cpp ExitSpace.cpp GemSpace.cpp StandardSpace.cpp StartSpace.cpp TreasureSpace.cpp Timer.cpp Player.cpp

INCLUDES = Menu.hpp InputValidation.hpp Dice.hpp Game.hpp Board.hpp Space.hpp ExitSpace.hpp GemSpace.hpp StandardSpace.hpp StartSpace.hpp TreasureSpace.hpp Timer.hpp Player.hpp

output: ${OBJS} ${INCLUDES}
	${CXX} ${CXXFLAGS} ${OBJS} -o output

${OBS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o output -f