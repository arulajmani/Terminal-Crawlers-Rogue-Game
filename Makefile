EXEC = cc3k
OBJECTS = main.o view.o slayer.o charizard.o chamber.o game.o factory.o floor.o character.o human.o player.o elf.o dwarf.o orc.o enemy.o goblin.o werewolf.o phoenix.o troll.o vampire.o merchant.o merchanthoard.o normalhoard.o smallhoard.o concretedragonhoard.o publisherdragonhoard.o concretedragon.o item.o gold.o subscriberdragon.o potion.o rh.o ba.o bd.o ph.o wa.o wd.o gameelement.o
CXX = g++
CXXFLAGS = -std=c++14 -Werror=vla -MMD
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lncurses

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
