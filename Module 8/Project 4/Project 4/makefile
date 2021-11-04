CXX = g++
CXXFLAGS = -std=c++0x

OBJS = main.o Menu.o InputValidation.o Barbarian.o BlueMen.o Creature.o CreatureList.o Dice.o Fight.o HarryPotter.o Medusa.o Tournament.o Vampire.o

SRCS = main.cpp Menu.cpp InputValidation.cpp Barbarian.cpp BlueMen.cpp Creature.cpp CreatureList.cpp Dice.cpp Fight.cpp HarryPotter.cpp Medusa.cpp Tournament.cpp Vampire.cpp

INCLUDES = Menu.hpp InputValidation.hpp Barbarian.hpp BlueMen.hpp Creature.hpp CreatureList.hpp Dice.hpp Fight.hpp HarryPotter.hpp Medusa.hpp Tournament.hpp Vampire.hpp

output: ${OBJS} ${INCLUDES}
	${CXX} ${CXXFLAGS} ${OBJS} -o output

${OBS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o output -f