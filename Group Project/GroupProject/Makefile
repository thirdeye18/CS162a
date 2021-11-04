CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall

OBJS = Tool.o Rock.o Paper.o Scissors.o RPSGame.o play_game.o inputValidation.o

SRCS = Tool.cpp Rock.cpp Paper.cpp Scissors.cpp RPSGame.cpp play_game.cpp inputValidation.cpp

INCLUDES = Tool.hpp Rock.hpp Paper.hpp Scissors.hpp RPSGame.hpp inputValidation.hpp

rps_game: ${OBJS} ${INCLUDES}
	${CXX} ${CXXFLAGS} ${OBJS} -o rps_game

${OBS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -rf ${OBJS} rps_game
